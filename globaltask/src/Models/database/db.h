#pragma once

#include <algorithm>
#include <fstream>
#include <iostream> #include <map>
#include <random>
#include <sstream>
#include <typeinfo>
#include <vector>
#include<string>

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
  virtual void save(fstream &stream) = 0;
  virtual void get(ifstream &stream) = 0;
  virtual string isEntryExists(ifstream &stream) = 0;

  AFieldORM(const string &key, const char *type) : key(key), type(type) {}

  string getKey() { return this->key; }

  const char *getType() { return this->type; }

  void setSize(int size) { this->size = size; }

  virtual int getSize() { return this->size; }

  void setIsAutoGenerate(bool value = false) { this->isAutoGenerate = value; }

  virtual void generate() {}
};

class Storage {
private:
  const std::string DB_FOLDER = "./database/";
  const char *name;

public:
  explicit Storage(const char *name) : name(name) {}

  void get(vector<AFieldORM *> fields, int &position) {
    ifstream file(DB_FOLDER + static_cast<std::string>(this->name),
                  std::ios::in | ios::binary);

    long fileSize;
    file.seekg(0, ios::end);
    fileSize = file.tellg();
    file.seekg(position, ios::beg);

    for (auto &field : fields) {
      field->setSize(0);
      // cout << position << " " << fileSize << endl;
      if (file.tellg() >= fileSize) {
        position = -1;
        break;
      }
      field->get(file);
      position += field->getSize();
    }

    file.close();
  }

  void saveOne(AFieldORM *field) {
    system("mkdir -p ./database");

    fstream file(DB_FOLDER + static_cast<std::string>(this->name),
                 std::ios::out | ios::binary | std::ios_base::app);

    field->save(file);

    file.close();
  }

  void save(vector<AFieldORM *> fields, int cursor = -1) {
    system("mkdir -p ./database");

    string path = DB_FOLDER + static_cast<std::string>(this->name);

    fstream file;

    if (cursor >= 0) {
      file = fstream(path, ios::in | std::ios::out | ios::binary);
      file.seekp(cursor, ios_base::beg);
    } else {
      file = fstream(path, std::ios::out | ios::binary | std::ios_base::app);
    }

    for (auto &field : fields) {
      field->save(file);
    }

    file.close();
  }

  bool isContains(AFieldORM *field, vector<AFieldORM *> checkRequired) {
    for (auto &check : checkRequired) {
      if (check->getKey() == field->getKey()) {
        return true;
      }
    }
    return false;
  }

  void isEntryExists(vector<AFieldORM *> fields,
                     vector<AFieldORM *> checkRequired,
                     vector<string> &errors) {
    // cout << "__Storage is exists " << endl;
    ifstream file(DB_FOLDER + static_cast<std::string>(this->name),
                  std::ios::in | ios::binary);

    int position = 0;

    file.seekg(0, ios::end);
    long fileSize = file.tellg();
    file.seekg(position, ios::beg);
    // cout << "File size: " << fileSize << endl;

    while (position >= 0) {
      // cout << "Current position: " << position << endl;
      for (auto &field : fields) {
        // cout << "Current field: " << field->getKey() << endl;
        if (file.tellg() >= fileSize) {
          position = -1;
          break;
        }
        string value = field->isEntryExists(file);
        if (value.length() != 0 && this->isContains(field, checkRequired)) {
          errors.push_back("Found same field " + field->getKey() + ": " +
                           value);
        }
        // cout << "Field size: " << field->getSize() << endl;
        position += field->getSize();
      }
    }
  }
};

template <class T> class BaseField : public AFieldORM {
protected:
  T value;

public:
  BaseField(const string &key, const T &value, const char *type)
      : AFieldORM(key, type), value(value) {}

  explicit BaseField(const string &key, const char *type)
      : AFieldORM(key, type) {}

  T getValue() { return this->value; }

  virtual void save(fstream &stream) = 0;
  virtual void get(ifstream &stream) = 0;

  virtual string isEntryExists(ifstream &stream) {
    T currentValue = this->value;
    this->get(stream);
    T gotValue = this->value;
    this->value = currentValue;
    // cout << "Current value: " << currentValue << " "
    // << "Got value: " << gotValue << endl;
    if (gotValue == currentValue) {
      return currentValue + "";
    }
    return {};
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
  }

public:
  explicit Schema(initializer_list<ASchemaField *> list) : schemaFields(list) {
    this->sortFields();
  }

  explicit Schema(initializer_list<ASchemaField *> list,
                  initializer_list<ASchemaField *> extendedFields)
      : schemaFields(list) {
    for (auto &extendedItem : extendedFields) {
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
  int cursor = 0;
  virtual void save() { this->storage->save(this->fields); }

  void checkUnique(vector<AFieldORM *> pfields, vector<string> &errors) {
    vector<AFieldORM *> checkRequired = {};
    for (auto &schemaField : this->schema->getSchemaFields()) {
      for (auto &field : pfields) {
        if (schemaField->getUnique() &&
            schemaField->getName() == field->getKey()) {
          // cout << "Check required: " << field->getKey() << endl;
          checkRequired.push_back(field);
        }
      }
    }
    this->storage->isEntryExists(pfields, checkRequired, errors);
  }

  void checkNames(vector<string> &errors) {
    for (auto &schemaField : this->schema->getSchemaFields()) {
      bool isMatch = false;
      for (auto &field : this->fields) {
        if (field->getKey() == schemaField->getName() &&
            schemaField->getRequired()) {
          isMatch = true;
        }
      }
      if (!isMatch) {
        errors.push_back("No such field: " + schemaField->getName());
      }
    }
  }

  void checkTypes(vector<string> &errors) {
    for (auto &schemaField : this->schema->getSchemaFields()) {
      bool isMatch = false;
      for (auto &field : this->fields) {
        if (schemaField->getType() == field->getType() &&
            schemaField->getName() == field->getKey()) {
          isMatch = true;
        }
      }
      if (!isMatch) {
        errors.push_back("No such type: " + schemaField->getName() +
                         " current type: " + schemaField->getType() +
                         " required");
      }
    }
  }

  void checkData(vector<string> &errors) {
    this->checkNames(errors);
    this->checkTypes(errors);
    this->checkUnique(this->fields, errors);
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
        tempField->setIsAutoGenerate(true);
        tempField->generate();
        this->fields.push_back(tempField);
      }
    }
    this->fields.insert(this->fields.end(), list);
    this->sortFields();
    this->checkData(errors);
    if (errors.size() == 0) {
      this->save();
    } else {
      for (auto &message : errors) {
        cout << message << endl;
      }
    }
  }

  template <class T>
  void updateOne(AFieldORM *searchField,
                 initializer_list<AFieldORM *> newFields) {
    vector<AFieldORM *> currentFields = findOne<T>(searchField);
    int position = this->cursor;

    int recordSize = 0;
    for (auto &currentField : currentFields) {
      recordSize += currentField->getSize();
      for (auto &newField : newFields) {
        if (newField->getKey() == currentField->getKey()) {
          currentField = newField;
        }
      }
    }

    for (auto &field : currentFields) {
      for (auto &schemaFeild : this->schema->getSchemaFields()) {
        if (field->getKey() == schemaFeild->getName() &&
            field->getType() == schemaFeild->getType() &&
            schemaFeild->getIsAutoGenerate()) {
          // cout << "Generating field " << field->getKey() << endl;
          field->setIsAutoGenerate(true);
          field->generate();
        }
      }
    }

    vector<string> errors{};
    this->checkUnique(currentFields, errors);
    if (errors.size() != 0) {
      for (auto &item : errors) {
        cout << item << endl;
      }
      return;
    }

    position -= recordSize;
    // cout << "Overwriting to " << position << endl;
    this->storage->save(currentFields, position);
  }

  template <class T> vector<vector<AFieldORM *>> find(AFieldORM *model) {
    auto castedModel = dynamic_cast<T *>(model);
    if (!castedModel) {
      return {};
    }

    int position = 0;
    vector<vector<AFieldORM *>> models = {};

    while (position >= 0) {
      vector<AFieldORM *> list{};
      for (auto &schemaFeild : this->schema->getSchemaFields()) {
        list.push_back(schemaFeild->getPureField());
      }
      this->storage->get(list, position);
      for (auto &item : list) {
        auto casted = dynamic_cast<T *>(item);
        if (!casted) {
          continue;
        }
        if (casted->getValue() == castedModel->getValue() &&
            item->getKey() == model->getKey()) {
          models.push_back(list);
        }
      }
    }
    return models;
  }

  template <class T> vector<AFieldORM *> findOne(AFieldORM *model) {
    auto castedModel = dynamic_cast<T *>(model);
    if (!castedModel) {
      return {};
    }

    // getting schema fields
    vector<AFieldORM *> iterableFields{};
    for (auto &schemaFeild : this->schema->getSchemaFields()) {
      // cout << "Getting pure field: " << schemaFeild->getName() << endl;
      iterableFields.push_back(schemaFeild->getPureField());
    }

    this->cursor = 0;

    while (this->cursor >= 0) {
      // cout << "FindOne Current Position: " << this->cursor << endl;
      this->storage->get(iterableFields, this->cursor);
      for (auto &iterableField : iterableFields) {
        auto casted = dynamic_cast<T *>(iterableField);
        if (!casted) {
          continue;
        }
        if (casted->getValue() == castedModel->getValue() &&
            iterableField->getKey() == model->getKey()) {
          return iterableFields;
        }
      }
    }
    return {};
  }
};

class StringFieldORM : public BaseField<string> {
protected:
  int stringSize = 255;

public:
  StringFieldORM(const string &key, const string &value)
      : BaseField(key, value, typeid(StringFieldORM).name()) {}

  explicit StringFieldORM(const string &key)
      : BaseField(key, typeid(StringFieldORM).name()) {}

  virtual void save(fstream &stream) override {
    int _size = this->stringSize;
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

  int getSize() override { return this->stringSize; }

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
class IntFieldORM : public BaseField<int> {
public:
  IntFieldORM(const string &key, const int &value)
      : BaseField(key, value, typeid(*this).name()) {}

  void save(fstream &stream) override {
    // cout << "Saving value: " << this->value << endl;
    stream.write(reinterpret_cast<char *>(&this->value), sizeof(int));
  };

  void get(ifstream &stream) override {
    this->size = sizeof(int);
    stream.read(reinterpret_cast<char *>(&this->value), this->size);
  };

  explicit IntFieldORM(const string &key)
      : BaseField(key, typeid(*this).name()) {}
};

class BoolFieldORM : public BaseField<bool> {
public:
  BoolFieldORM(const string &key, const bool &value)
      : BaseField(key, value, typeid(*this).name()) {}

  void save(fstream &stream) override {
    stream.write(reinterpret_cast<char *>(&this->value), sizeof(bool));
  };

  void get(ifstream &stream) override {
    this->size = sizeof(bool);
    stream.read(reinterpret_cast<char *>(&this->value), sizeof(bool));
    // cout << "Bool: " << this->value << endl;
  };

  explicit BoolFieldORM(const string &key)
      : BaseField(key, typeid(*this).name()) {}
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
  for (auto &userField : newUser) {
    if (userField->getKey() == key) {
      return dynamic_cast<T *>(userField);
    }
  }
  return new T(key);
}