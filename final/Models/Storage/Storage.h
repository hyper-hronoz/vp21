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
 public:
  virtual ~AFieldORM() {}
  virtual void save(ofstream &stream) = 0;
  virtual void get(ifstream &stream) = 0;

  AFieldORM(const string& key, const char *type) : key(key), type(type) {}

  string getKey() {
    return this->key;
  }

  const char* getType() {
    return this->type;
  }
};

class Storage {
 private:
  const std::string DB_FOLDER = "./database/";
  const char* name;

 public:
  explicit Storage(const char* name) : name(name) {}

  void get(vector<AFieldORM*> fuilds) {
    ifstream file(DB_FOLDER +
    static_cast<std::string>(this->name),
    std::ios::in | ios::binary);

    for (auto &fuild : fuilds) {
      fuild->get(file);
    }

    file.close();
  }

  void get(AFieldORM* model) {
    ifstream file(DB_FOLDER +
    static_cast<std::string>(this->name),
    std::ios::in | ios::binary);

    model->get(file);

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

  virtual string getName() {
      return this->_name; }
};

class Schema {
 private:
  vector<ASchemaFuild*> schemaFuilds;

 public:
  explicit Schema(initializer_list<ASchemaFuild*> list)
      : schemaFuilds(list) {}

  explicit Schema(Schema schema, initializer_list<ASchemaFuild*> list) {
    for (ASchemaFuild* extendedItem : list) {
      for (ASchemaFuild* item : this->schemaFuilds) {
        if (item->getName() == extendedItem->getName()) {
          cout << "Тревога, у нас одинаковое имя при наследовании!" << endl;
          return;
        }
      }
      this->schemaFuilds.push_back(extendedItem);
    }
  }

  void print() {
    for (ASchemaFuild* item : this->schemaFuilds) {
      item->print();
    }
  }

  virtual ~Schema() {
    for (auto &item : this->schemaFuilds) {
      delete item;
    }
    this->schemaFuilds.clear();
  }

  vector<ASchemaFuild*> getSchemaFuilds() const {
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
    for (auto &f : fields) {
      this->storage->save(f);
    }
  }

  void checkData(vector<string> &errors) {
    for (auto &schemaFeild : this->schema.getSchemaFuilds()) {
      bool isMatchNames = false;
      for (auto &field : this->fields) {
        if (schemaFeild->getName() == field->getKey()) {
          isMatchNames = true;
        }
      }

      bool isMatchTypes = false;
      for (auto &field : this->fields) {
        if (schemaFeild->getType() == field->getType() && isMatchNames) {
          isMatchTypes = true;
        }
      }

      if (!isMatchNames && schemaFeild->getRequired() == true) {
        errors.push_back("No such field: " + schemaFeild->getName());
      }

      if (!isMatchTypes) {
        errors.push_back("No such type: " + schemaFeild->getName());
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
    vector<AFieldORM*> list{};
    for (auto &schemaFeild : this->schema.getSchemaFuilds()) {
      list.push_back(schemaFeild->getPureFuild());
    }
    this->storage->get(list);
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
    int size = this->value.length();
    stream.write(reinterpret_cast<char*>(&size), sizeof(int));
    stream.write(this->value.c_str(), size);
  };

  void get(ifstream &stream) override{
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
    stream.read(reinterpret_cast<char*>(&this->value), sizeof(int));
    cout << this->value << endl;
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
    stream.read(reinterpret_cast<char*>(&this->value), sizeof(bool));
    cout << this->value << endl;
  };

  explicit BoolFieldORM(const string &key) :
    BaseFuild(key, typeid(*this).name()) {}
};

class UserProfile: public BaseORM {
 public:
  explicit UserProfile(const Schema &schema) :
    BaseORM(schema, typeid(this).name()) {}
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

// int main() {
//   Schema userSchema({
//     (new SchemaFuild<IntFieldORM>("id"))->required(true),
//     (new SchemaFuild<IntFieldORM>("email"))->required(true)->unique(true),
//     (new SchemaFuild<BoolFieldORM>("isEmailConfirmed"))->required(true)
//   });
//
//   Schema providerSchema(userSchema, {
//       (new SchemaFuild<StringFieldORM>("product"))->required(true)->unique(false),
//   });
//
//   Schema employerSchema(userSchema, {
//       (new SchemaFuild<StringFieldORM>("jobTitle"))->required(true)->unique(false),
//   });
//
//   UserProfile userModel(userSchema);
//
//   // userModel.create({
//   //   new IntFieldORM("id", 1000),
//   //   new IntFieldORM("email", 8),
//   //   new BoolFieldORM("isEmailConfirmed", false),
//   // });
//
//   userModel.findOne<IntFieldORM>(new IntFieldORM("email", 8));
//
//   return 0;
// }


