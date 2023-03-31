#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<typeinfo>

using namespace std;

class AFieldORM {
 protected:
  string key;
  const char* type;
  int size;
 public:
  virtual ~AFieldORM() {}
  virtual void save(ofstream &stream) = 0;
  virtual void get(ifstream &stream) = 0;
  virtual bool isEntryExists(ifstream &stream) = 0;

  AFieldORM(const string& key, const char *type) : key(key), type(type) {}

  string getKey() {
    return this->key;
  }

  const char* getType() {
    return this->type;
  }

  void setSize(int size) {
    this->size = size;
  }

  int getSize() {
    return this->size;
  }
};

class Storage {
 private:
  const std::string DB_FOLDER = "./database/";
  const char* name;

 public:
  explicit Storage(const char* name) : name(name) {}

  void get(vector<AFieldORM*> fuilds, int &position) {
    ifstream file(DB_FOLDER +
    static_cast<std::string>(this->name),
    std::ios::in | ios::binary);

    long fileSize;
    file.seekg(0, ios::end);
    fileSize = file.tellg();
    file.seekg(position, ios::beg);

    for (auto &fuild : fuilds) {
      fuild->setSize(0);
      if (file.tellg() >= fileSize) {
        position = -1;
        break;
      }
      fuild->get(file);
      position += fuild->getSize();
    }

    file.close();
  }

  void save(AFieldORM *model) {
    system("mkdir -p ./database");

    ofstream file(DB_FOLDER +
    static_cast<std::string>(this->name),
    std::ios::out | ios::binary | std::ios_base::app);

    model->save(file);

    file.close();
  }

  bool isEntryExists(vector<AFieldORM*> fuilds, AFieldORM *target) {
    ifstream file(DB_FOLDER +
    static_cast<std::string>(this->name),
    std::ios::in | ios::binary);

    long fileSize;
    file.seekg(0, ios::end);
    fileSize = file.tellg();

    int position = 0;
    file.seekg(position, ios::beg);

    while (position >= 0) {
      bool isExists = false;
      for (auto &fuild : fuilds) {
        // cout << "Position: " << position << " " << fileSize << endl;
        fuild->setSize(0);
        if (file.tellg() >= fileSize) {
          position = -1;
          break;
        }
        if (fuild->isEntryExists(file) && fuild->getKey() == target->getKey()) {
          isExists = true;
        }
        position += fuild->getSize();
      }
      if (isExists) return isExists;
    }

    file.close();
    return false;
  }
};

template<class T>
class BaseFuild : public AFieldORM {
 protected:
  T value;

 public:
  BaseFuild(const string& key, const T& value, const char* type) :
    AFieldORM(key, type), value(value) {}

  explicit BaseFuild(const string& key, const char* type) :
    AFieldORM(key, type) {}

  T getValue() {
    return this->value;
  }

  virtual void save(ofstream &stream) = 0;
  virtual void get(ifstream &stream) = 0;

  virtual bool isEntryExists(ifstream &stream) {
    // cout << "Type: " << typeid(T).name() << endl;
    T constValue = this->value;
    this->get(stream);
    T gottedValue = this->value;
    this->value = constValue;
    // cout << "Gotted value: " << gottedValue << " Current value: " << constValue << endl;
    // cout << &constValue << " " << &this->value << endl;
    if (gottedValue == constValue) {
      // cout << "Found same" << endl;
      // cout << this->value << " " << constValue << endl;
      return true;
    }
    return false;
  }
};

class ASchemaFuild {
 protected:
  string _name;
  bool _isRequired;
  bool _isUnique;
  const char* _type;

 public:
  virtual void print() = 0;
  virtual bool getRequired() = 0;
  virtual bool getUnique() = 0;

  ASchemaFuild(string name, const char* type) : _name(name), _type(type) {}
  virtual ~ASchemaFuild() {}

  virtual const char* getType() {
      return this->_type;
  }

  virtual AFieldORM* getPureFuild() = 0;

  virtual string getName() const {
      return this->_name; }
};

class Schema {
 private:
  vector<ASchemaFuild*> schemaFuilds;

 public:
  explicit Schema(initializer_list<ASchemaFuild*> list)
      : schemaFuilds(list) {}

  explicit Schema(initializer_list<ASchemaFuild*> list,
      initializer_list<ASchemaFuild*> extendedFuilds) : schemaFuilds(list) {
    for (auto &extendedItem : extendedFuilds) {
      for (auto &item : list) {
        if (item->getName() == extendedItem->getName()) {
          cout << "Тревога, у нас одинаковое имя при наследовании!" << endl;
          return;
        }
      }
      this->schemaFuilds.push_back(extendedItem);
    }
  }

  void print() {
    for (auto &item : this->schemaFuilds) {
      item->print();
    }
  }

  vector<ASchemaFuild*> getSchemaFields() const {
    return this->schemaFuilds;
  }
};

class BaseORM {
 protected:
  vector<AFieldORM*> fields;
  const Schema &schema;
  Storage *storage;

 private:
  virtual void save() {
    for (auto &field : fields) {
      this->storage->save(field);
    } }
  void checkData(vector<string> &errors) {
    for (auto &schemaField : this->schema.getSchemaFields()) {
      bool isMatchNames = false;
      for (auto &field : this->fields) {
        if (schemaField->getName() == field->getKey()) {
          isMatchNames = true;
        }
      }

      bool isMatchTypes = false;
      for (auto &field : this->fields) {
        if (schemaField->getType() == field->getType() && isMatchNames) {
          isMatchTypes = true;
        }
      }

      bool isEntryExists = false;
      for (auto &target : this->fields) {
        if (schemaField->getUnique() && target->getKey() == schemaField->getName()) {
          // cout << "Schema fuild: " << schemaField->getName() << endl;
          isEntryExists = this->storage->isEntryExists(fields, target);
        }
      }

      if (!isMatchNames && schemaField->getRequired() == true) {
        errors.push_back("No such field: " + schemaField->getName());
      }

      if (!isMatchTypes) {
        errors.push_back("No such type: " + schemaField->getName());
      }

      if (isEntryExists) {
        errors.push_back("This entry already exists: "
                + schemaField->getName());
      }
    }
  }

 public:
  explicit BaseORM(const Schema &schema, const char* DBName)
    : schema(schema), storage(new Storage(DBName)) {}

  virtual ~BaseORM() {
    for (auto &f : fields) {
      delete f;
    }
    delete this->storage;
  }

  void create(initializer_list<AFieldORM*> list) {
    vector<string> errors{};
    this->fields = list;
    this->checkData(errors);
    if (errors.size() == 0) {
      this->save();
    } else {
      for (auto &message : errors) {
        cout << message << endl;
      }
    }
  }

  template<class T> vector<AFieldORM*> findOne(AFieldORM *model) {
    auto castedModel = dynamic_cast<T*>(model);
    if (!castedModel) {
      return {};
    }
    // getting schema fuilds
    vector<AFieldORM*> list{};
    for (auto &schemaFeild : this->schema.getSchemaFields()) {
      list.push_back(schemaFeild->getPureFuild());
    }

    int position = 0;

    while (position >= 0) {
      this->storage->get(list, position);
      for (auto &item : list) {
        auto casted = dynamic_cast<T*>(item);
        if (!casted) {
          continue;
        }
        if (casted->getValue() == castedModel->getValue()) {
          return list;
        }
      }
    }
    return {};
  }
};

class StringFieldORM : public BaseFuild<string> {
 public:
  explicit StringFieldORM(const string &key, const string &value) :
    BaseFuild(key, value, typeid(*this).name()) {}

  explicit StringFieldORM(const string &key) :
    BaseFuild(key, typeid(*this).name()) {}

  void save(ofstream &stream) override {
    int _size = this->value.length();
    stream.write(reinterpret_cast<char*>(&_size), sizeof(int));
    stream.write(this->value.c_str(), _size);
  };

  void get(ifstream &stream) override {
    int _size;
    stream.read(reinterpret_cast<char *>(&_size), sizeof(int));
    // cout << "Size: " << _size << endl;
    char *buff = new char[_size + 1];
    stream.read(buff, _size);
    buff[_size] = '\0';
    // cout << "Buf: " << buff << endl;
    this->value = buff;
    this->size += _size;
    this->size += sizeof(int);
    delete[] buff;
  };
};

class IntFieldORM : public BaseFuild<int> {
 public:
  explicit IntFieldORM(const string &key, const int &value) :
    BaseFuild(key, value, typeid(*this).name()) {}

  void save(ofstream &stream) override {
    stream.write(reinterpret_cast<char*>(&this->value), sizeof(int));
  };

  void get(ifstream &stream) override {
    this->size = sizeof(int);
    stream.read(reinterpret_cast<char*>(&this->value), this->size);
  };

  explicit IntFieldORM(const string &key) :
    BaseFuild(key, typeid(*this).name()) {}
};

class BoolFieldORM : public BaseFuild<bool> {
 public:
  explicit BoolFieldORM(const string &key, const bool &value) :
    BaseFuild(key, value, typeid(*this).name()) {}

  void save(ofstream &stream) override {
    stream.write(reinterpret_cast<char*>(&this->value), sizeof(bool));
  };

  void get(ifstream &stream) override {
    this->size = sizeof(bool);
    stream.read(reinterpret_cast<char*>(&this->value), sizeof(bool));
  };

  explicit BoolFieldORM(const string &key) :
    BaseFuild(key, typeid(*this).name()) {}
};


template<class T>
class SchemaFuild : public ASchemaFuild {
 public:
  explicit SchemaFuild(string name) : ASchemaFuild(name, typeid(T).name()) {}

  SchemaFuild* required(bool value = false) {
      this->_isRequired = value;
      return this;
  }

  SchemaFuild* unique(bool value = false) {
      this->_isUnique = value;
      return this;
  }


  void print() override {
      cout << "{" << "\n" <<
         "     " << "name: " << this->_name << ","  << "\n" <<
         "     " << "unique: " << this->_isUnique << ","  << "\n" <<
         "     " << "required: " << this->_isRequired << ","  << "\n" <<
         "     " << "type: " << this->_type << "\n" <<
      "}" << ',' << endl;
  }

  bool getUnique() override {
      return this->_isUnique;
  }

  bool getRequired() override {
      return this->_isRequired;
  }

  AFieldORM* getPureFuild() override {
    return new T(this->getName());
  }
};

template<class T>
T* HardCast(vector<AFieldORM*> newUser, string key) {
  for (auto &userFuild : newUser) {
    if (userFuild->getKey() == key) {
      return dynamic_cast<T*>(userFuild);
    }
  }
  return {};
}

class User : public BaseORM {
 public:
  explicit User(initializer_list<ASchemaFuild*> extendedFuilds = {}, const char* type = typeid(User).name()) :
    BaseORM(*new Schema({
    (new SchemaFuild<IntFieldORM>("id"))->required(true)->unique(true),
    (new SchemaFuild<StringFieldORM>("email"))->required(true)->unique(true),
    (new SchemaFuild<BoolFieldORM>("isEmailConfirmed"))->required(true),
  }, extendedFuilds), type) {}
};

class Employer : public User {
 public:
  Employer() : User({
    (new SchemaFuild<StringFieldORM>("job title"))->required(true),
  }, typeid(this).name()) {}
};

int main() {
  User userModel;

  Employer employer;

  employer.create({
    new IntFieldORM("id", 32),
    new StringFieldORM("email", "vladilenzia227@mail.ru"),
    new BoolFieldORM("isEmailConfirmed", false),
    new StringFieldORM("job title", "fucking job"),
  });

  // userModel.create({
  //   new IntFieldORM("id", 32),
  //   new StringFieldORM("email", "vladilenzia227@mail.ru"),
  //   new BoolFieldORM("isEmailConfirmed", false),
  // });
  //
  // userModel.create({
  //   new IntFieldORM("id", 10),
  //   new StringFieldORM("email", "moryak227res227@mail.ru"),
  //   new BoolFieldORM("isEmailConfirmed", true),
  // });
  //
  // userModel.create({
  //   new IntFieldORM("id", 1),
  //   new StringFieldORM("email", "romaivanov@mail.ru"),
  //   new BoolFieldORM("isEmailConfirmed", true),
  // });
  //
  // vector<AFieldORM*> newUser = userModel.findOne<StringFieldORM>
  //   (new StringFieldORM("email", "moryak227res227@mail.ru"));
  //
  // IntFieldORM *newIntField = HardCast<IntFieldORM>(newUser, "id");
  // cout << "Final: " << newIntField->getValue() << endl;

  return 0;
}
