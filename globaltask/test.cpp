#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <typeinfo>
#include <vector>

using namespace std;

namespace uuid {
static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dis(0, 15);
static std::uniform_int_distribution<> dis2(8, 11);

std::string generate_uuid_v4() {
  std::stringstream ss;
  int i;
  ss << std::hex;
  for (i = 0; i < 8; i++) {
    ss << dis(gen);
  }
  ss << "-";
  for (i = 0; i < 4; i++) {
    ss << dis(gen);
  }
  ss << "-4";
  for (i = 0; i < 3; i++) {
    ss << dis(gen);
  }
  ss << "-";
  ss << dis2(gen);
  for (i = 0; i < 3; i++) {
    ss << dis(gen);
  }
  ss << "-";
  for (i = 0; i < 12; i++) {
    ss << dis(gen);
  };
  return ss.str();
}
} // namespace uuid

class AFieldORM {
protected:
  string key;
  const char *type;
  int size;
  bool isAutoGenerate;

public:
  virtual ~AFieldORM() {}
  virtual void save(ofstream &stream) = 0;
  virtual void get(ifstream &stream) = 0;
  virtual bool isEntryExists(ifstream &stream) = 0;

  AFieldORM(const string &key, const char *type) : key(key), type(type) {}

  string getKey() { return this->key; }

  const char *getType() { return this->type; }

  void setSize(int size) { this->size = size; }

  int getSize() { return this->size; }

  void setIsAutoGenerate(bool value = false) { this->isAutoGenerate = value; }

  virtual void generate() {}
};

class Storage {
private:
  const std::string DB_FOLDER = "./database/";
  const char *name;

public:
  explicit Storage(const char *name) : name(name) {}

  void get(vector<AFieldORM *> fuilds, int &position) {
    ifstream file(DB_FOLDER + static_cast<std::string>(this->name),
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

    ofstream file(DB_FOLDER + static_cast<std::string>(this->name),
                  std::ios::out | ios::binary | std::ios_base::app);

    model->save(file);

    file.close();
  }

  void update(AFieldORM *target) {}

  bool isEntryExists(vector<AFieldORM *> fuilds, AFieldORM *target) {
    ifstream file(DB_FOLDER + static_cast<std::string>(this->name),
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
      if (isExists)
        return isExists;
    }

    file.close();
    return false;
  }
};

template <class T> class BaseFuild : public AFieldORM {
protected:
  T value;

public:
  BaseFuild(const string &key, const T &value, const char *type)
      : AFieldORM(key, type), value(value) {}

  explicit BaseFuild(const string &key, const char *type)
      : AFieldORM(key, type) {}

  T getValue() { return this->value; }

  virtual void save(ofstream &stream) = 0;
  virtual void get(ifstream &stream) = 0;

  virtual bool isEntryExists(ifstream &stream) {
    // cout << "Type: " << typeid(T).name() << endl;
    T constValue = this->value;
    this->get(stream);
    T gottedValue = this->value;
    this->value = constValue;
    // cout << "Gotted value: " << gottedValue << " Current value: " <<
    // constValue << endl; cout << &constValue << " " << &this->value << endl;
    if (gottedValue == constValue) {
      // cout << "Found same" << endl;
      // cout << this->value << " " << constValue << endl;
      return true;
    }
    return false;
  }
};

class ASchemaField {
protected:
  string _name;
  bool _isRequired;
  bool _isUnique;
  bool _isAutoGenerate;
  const char *_type;

public:
  virtual void print() = 0;
  virtual bool getRequired() = 0;
  virtual bool getUnique() = 0;

  ASchemaField(string name, const char *type) : _name(name), _type(type) {}
  virtual ~ASchemaField() {}

  virtual const char *getType() { return this->_type; }

  virtual AFieldORM *getPureField() = 0;

  virtual string getName() const { return this->_name; }

  virtual bool getIsAutoGenerate() { return this->_isAutoGenerate; }
};

class Schema {
private:
  vector<ASchemaField *> schemaFields;

  static bool compareInterval(ASchemaField *field1, ASchemaField *field2) {
    return (field1->getName() < field2->getName());
  }

  void sortFields() {
    sort(this->schemaFields.begin(), this->schemaFields.end(), compareInterval);
    cout << "Sorted:" << endl;
    for (auto &field : this->schemaFields) {
        cout << field->getName() << endl;
    }
  }

public:
  explicit Schema(initializer_list<ASchemaField *> list) : schemaFields(list) {
    this->sortFields();
  }

  explicit Schema(initializer_list<ASchemaField *> list,
                  initializer_list<ASchemaField *> extendedFuilds)
      : schemaFields(list) {
    for (auto &extendedItem : extendedFuilds) {
      for (auto &item : list) {
        if (item->getName() == extendedItem->getName()) {
          cout << "Тревога, у нас одинаковое имя при наследовании!" << endl;
          return;
        }
      }
      this->schemaFields.push_back(extendedItem);
    }
    this->sortFields();
  }

  ~Schema() {
    for (auto p : this->getSchemaFields()) {
      delete p;
    }
    this->getSchemaFields().clear();
  }

  void print() {
    for (auto &item : this->schemaFields) {
      item->print();
    }
  }

  vector<ASchemaField *> getSchemaFields() const { return this->schemaFields; }
};

class BaseORM {
protected:
  vector<AFieldORM *> fields;
  Schema *schema;
  Storage *storage;

private:
  virtual void save() {
    for (auto &field : fields) {
      cout << "Saving: " << field->getKey() << endl;
      this->storage->save(field);
    }
  }

  void checkData(vector<string> &errors) {
    for (auto &schemaField : this->schema->getSchemaFields()) {

      // cout << "Schema field: " << schemaField->getName() << endl;
      bool isMatchNames = false;
      for (auto &field : this->fields) {
        if (schemaField->getName() == field->getKey()) {
          isMatchNames = true;
          break;
        }
      }

      bool isMatchTypes = false;
      for (auto &field : this->fields) {
        if (schemaField->getType() == field->getType() && isMatchNames) {
          isMatchTypes = true;
          break;
        }
      }

      bool isEntryExists = false;
      for (auto &target : this->fields) {
        if (schemaField->getUnique() &&
            target->getKey() == schemaField->getName()) {
          // cout << "Schema fuild: " << schemaField->getName() << endl;
          isEntryExists = this->storage->isEntryExists(fields, target);
          break;
        }
      }

      if (!isMatchNames && schemaField->getRequired() == true) {
        errors.push_back("No such field: " + schemaField->getName());
      }

      if (!isMatchTypes) {
        errors.push_back("No such type: " + schemaField->getName());
      }

      if (isEntryExists) {
        errors.push_back("This entry already exists: " +
                         schemaField->getName());
      }
    }
  }

  static bool compareInterval(AFieldORM *field1, AFieldORM *field2) {
    return (field1->getKey() < field2->getKey());
  }

  void sortFields() {
    sort(this->fields.begin(), this->fields.end(), compareInterval);
  }

public:
  explicit BaseORM(Schema *schema, const char *DBName)
      : schema(schema), storage(new Storage(DBName)) {}

  virtual ~BaseORM() {
    for (auto &field : fields) {
      delete field;
    }
    this->fields.clear();
    delete this->storage;
    delete this->schema;
  }

  void create(initializer_list<AFieldORM *> list) {
    this->fields = {};
    vector<string> errors{};
    for (auto &schemaField : this->schema->getSchemaFields()) {
      if (schemaField->getIsAutoGenerate()) {
        AFieldORM *tempField = schemaField->getPureField();
        cout << "Auto generate key: " << tempField->getKey() << endl;
        tempField->setIsAutoGenerate(true);
        tempField->generate();
        this->fields.push_back(tempField);
      }
    }
    this->fields.insert(this->fields.end(), list);
    this->checkData(errors);
    if (errors.size() == 0) {
        this->sortFields();
      this->save();
    } else {
      for (auto &message : errors) {
        cout << message << endl;
      }
    }
  }

  template <class T> void updateOne(AFieldORM *model, AFieldORM *replacer) {
    vector<AFieldORM *> fields = findOne<T>(model);
    for (auto &field : fields) {
      this->storage;
    }
    // cout << "Nothing to change in updateOne" << endl;
  }

  template <class T> vector<AFieldORM *> findOne(AFieldORM *model) {
    auto castedModel = dynamic_cast<T *>(model);
    if (!castedModel) {
      return {};
    }
    // getting schema fuilds
    vector<AFieldORM *> list{};
    for (auto &schemaFeild : this->schema->getSchemaFields()) {
      // cout << "Getting pure field: " << schemaFeild->getName() << endl;
      list.push_back(schemaFeild->getPureField());
    }

    int position = 0;

    while (position >= 0) {
      this->storage->get(list, position);
      for (auto &item : list) {
        auto casted = dynamic_cast<T *>(item);
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
protected:
  int stringSize = 255;

public:
  StringFieldORM(const string &key, const string &value)
      : BaseFuild(key, value, typeid(StringFieldORM).name()) {}

  explicit StringFieldORM(const string &key)
      : BaseFuild(key, typeid(StringFieldORM).name()) {}

  virtual void save(ofstream &stream) override {
    int _size = this->stringSize;
    cout << "Saving value: " << this->value << " Size: " << this->stringSize
         << endl;
    stream.write(this->value.c_str(), _size);
  };

  virtual void get(ifstream &stream) override {
    int _size = this->stringSize;
    // cout << "Size: " << _size << endl;
    char *buff = new char[_size + 1];
    stream.read(buff, _size);
    buff[_size] = '\0';
    // cout << "Buf: " << buff << endl;
    this->value = buff;
    this->size += _size;
    delete[] buff;
  };

  void generate() override {
    if (this->isAutoGenerate) {
      this->value = uuid::generate_uuid_v4();
    }
  }

  int getSize() { return this->stringSize; }

  friend bool operator>(StringFieldORM &str1, StringFieldORM &str2) {
    return str1.stringSize > str2.getSize();
  }
  friend bool operator<(StringFieldORM &str1, StringFieldORM &str2) {
    return str1.getSize() < str2.getSize();
  }
};

class LongString : public StringFieldORM {
private:
  void redifine() {
    this->type = typeid(LongString).name();
    this->stringSize = 1000;
  }

public:
  LongString(const string &key, const string &value)
      : StringFieldORM(key, value) {
    this->redifine();
  }

  explicit LongString(const string &key) : StringFieldORM(key) {
    this->redifine();
  }
};
//
class IntFieldORM : public BaseFuild<int> {
public:
  IntFieldORM(const string &key, const int &value)
      : BaseFuild(key, value, typeid(*this).name()) {}

  void save(ofstream &stream) override {
    cout << "Saving value: " << this->value << endl;
    stream.write(reinterpret_cast<char *>(&this->value), sizeof(int));
  };

  void get(ifstream &stream) override {
    this->size = sizeof(int);
    stream.read(reinterpret_cast<char *>(&this->value), this->size);
  };

  explicit IntFieldORM(const string &key)
      : BaseFuild(key, typeid(*this).name()) {}
};

class BoolFieldORM : public BaseFuild<bool> {
public:
  BoolFieldORM(const string &key, const bool &value)
      : BaseFuild(key, value, typeid(*this).name()) {}

  void save(ofstream &stream) override {
    stream.write(reinterpret_cast<char *>(&this->value), sizeof(bool));
  };

  void get(ifstream &stream) override {
    this->size = sizeof(bool);
    stream.read(reinterpret_cast<char *>(&this->value), sizeof(bool));
    // cout << "Bool: " << this->value << endl;
  };

  explicit BoolFieldORM(const string &key)
      : BaseFuild(key, typeid(*this).name()) {}
};

template <class T> class SchemaField : public ASchemaField {
public:
  explicit SchemaField(string name) : ASchemaField(name, typeid(T).name()) {}

  SchemaField *required(bool value = false) {
    this->_isRequired = value;
    return this;
  }

  SchemaField *autoGenerate(bool value = false) {
    if (this->_isUnique) {
      this->_isUnique = false;
    }
    this->_isAutoGenerate = value;
    return this;
  }

  SchemaField *unique(bool value = false) {
    if (this->_isAutoGenerate) {
      this->_isUnique = false;
    }
    this->_isUnique = value;
    return this;
  }

  void print() override {
    cout << "{"
         << "\n"
         << "     "
         << "name: " << this->_name << ","
         << "\n"
         << "     "
         << "unique: " << this->_isUnique << ","
         << "\n"
         << "     "
         << "required: " << this->_isRequired << ","
         << "\n"
         << "     "
         << "type: " << this->_type << "\n"
         << "}" << ',' << endl;
  }

  bool getUnique() override { return this->_isUnique; }

  bool getRequired() override { return this->_isRequired; }

  AFieldORM *getPureField() override { return new T(this->getName()); }
};

template <class T> T *HardCast(vector<AFieldORM *> newUser, string key) {
  for (auto &userFuild : newUser) {
    if (userFuild->getKey() == key) {
      return dynamic_cast<T *>(userFuild);
    }
  }
  return new T(key);
}

class User : public BaseORM {
public:
  User(initializer_list<ASchemaField *> extendedFuilds = {},
       const char *type = typeid(User).name())
      : BaseORM(
            new Schema(
                {(new SchemaField<StringFieldORM>("email"))
                     ->required(true)
                     ->unique(true),
                 (new SchemaField<IntFieldORM>("age"))->required(true),
                 (new SchemaField<StringFieldORM>("name"))->required(true),
                 (new SchemaField<StringFieldORM>("password"))->required(true)},
                extendedFuilds),
            type) {}

  virtual void showPass() = 0;
};

class Provider : public User {
public:
  Provider()
      : User(
            {
                (new SchemaField<StringFieldORM>("product _id"))->required(true),
            },
            typeid(this).name()) {}

  void showPass() {}
};

class Employer : public User {
public:
  Employer()
      : User(
            {
                (new SchemaField<StringFieldORM>("title"))->required(true),
            },
            typeid(this).name()) {}

  void showPass() {}
};

class ProductType : BaseORM {
public:
  ProductType(initializer_list<ASchemaField *> extendedFuilds = {},
              const char *type = typeid(ProductType).name())
      : BaseORM(new Schema({
                            (new SchemaField<StringFieldORM>("type"))
                                ->required(true)
                                ->unique(true)},
                           extendedFuilds),
                type) {}
};

class Product : public BaseORM {
private:
  string id;
  string type;
  string name;
  int price;
  int amount;

  void update(vector<AFieldORM *> fields) {
    if (!fields.size()) {
      return;
    }
    this->id = HardCast<StringFieldORM>(fields, "_id")->getValue();
    this->name = HardCast<StringFieldORM>(fields, "name")->getValue();
    this->type = HardCast<StringFieldORM>(fields, "type")->getValue();
    this->price = HardCast<IntFieldORM>(fields, "price")->getValue();
    this->amount = HardCast<IntFieldORM>(fields, "amount")->getValue();
  }

public:
  Product(vector<AFieldORM *> fields = {},
          initializer_list<ASchemaField *> extendedFuilds = {},
          const char *type = typeid(Product).name())
      : BaseORM(new Schema(
                    {
                     (new SchemaField<StringFieldORM>("type"))->required(true),
                     (new SchemaField<StringFieldORM>("name"))
                         ->required(true)
                         ->unique(true),
                     (new SchemaField<IntFieldORM>("price"))
                         ->required(true)
                         ->unique(true),
                     (new SchemaField<IntFieldORM>("amount"))->required(true)},
                    extendedFuilds),
                type) {
    this->update(fields);
  }

  void operator=(vector<AFieldORM *> fields) { this->update(fields); }

  friend ostream &operator<<(ostream &output, const Product &product) {
    output << "_id: " << product.id << endl;
    output << "name: " << product.name << endl;
    output << "type: " << product.type << endl;
    output << "price: " << product.price << endl;
    output << "amount: " << product.amount << endl;
    return output;
  }

  friend istream &operator>>(istream &input, Product &product) {
    cout << "Не несет полезной нагрузки" << endl;
    return input;
  }
};

class JobTitle : BaseORM {
  JobTitle(initializer_list<ASchemaField *> extendedFuilds = {},
           const char *type = typeid(JobTitle).name())
      : BaseORM(new Schema({(new SchemaField<StringFieldORM>("job title"))
                                ->required(true)
                                ->unique(true)},
                           extendedFuilds),
                type) {}
};

int main() {
  Product product;

  product.create({
      new StringFieldORM( "type", "toys"),
      new IntFieldORM("price", 10),
      new StringFieldORM("name", "whirligig"),
      new IntFieldORM("amount", 20),
  });

  Product newProduct = product.findOne<StringFieldORM>(new StringFieldORM("type", "whirligig"));

  cout << newProduct << endl;

  // comparing sizes in bytes
  // StringFieldORM *test1 = new StringFieldORM("hello", "there");
  // LongString *longString = new LongString("fuck", "you");
  // cout << (test1 < longString) << endl;

  // Provider provider;
  //
  // Employer employer;
  //
  // employer.create({
  //     new StringFieldORM("email", "vladilenzia227@mail.ru"),
  //     new StringFieldORM("sername", "fucking sername"),
  //     new StringFieldORM("password", "fucking password"),
  //     new StringFieldORM("job title", "fucking job"),
  //     new IntFieldORM("age", 18),
  //     new StringFieldORM("name", "Hronoz"),
  // });
  //
  // vector<AFieldORM *> newUser = employer.findOne<StringFieldORM>(
  //     new StringFieldORM("email", "vladilenzia227@mail.ru"));
  //
  // if (newUser.size() == 0) {
  //   cout << "Пользователь не найден" << endl;
  // } else {
  //   StringFieldORM *newUserId = HardCast<StringFieldORM>(newUser, "id");
  //   StringFieldORM *newUserEmail = HardCast<StringFieldORM>(newUser,
  //   "email"); cout << newUserId->getValue() << endl; cout <<
  //   newUserEmail->getValue() << endl; delete newUserId; delete newUserEmail;
  // }

  return 0;
}
