#pragma once
#include "User.h"
#include "vector"

class Provider : public User {
protected:
  std::string id;
  std::string type;

  void update(vector<AFieldORM *> fields) {
    if (!fields.size()) {
      return;
    }
    this->id = HardCast<StringFieldORM>(fields, "_id")->getValue();
    this->type = HardCast<StringFieldORM>(fields, "type")->getValue();
    this->name = HardCast<StringFieldORM>(fields, "name")->getValue();
    this->email = HardCast<StringFieldORM>(fields, "email")->getValue();
  }

public:
  Provider(vector<AFieldORM *> fields = {})
      : User(
            {
                (new SchemaField<StringFieldORM>("type"))->required(true),
            },
            typeid(this).name()) {
    this->update(fields);
  }

  friend ostream &operator<<(ostream &output, const Provider &provider) {
    output << "_id: " << provider.id << endl;
    output << "email: " << provider.email << endl;
    output << "type: " << provider.type << endl;
    output << "name: " << provider.name << endl;
    output << "age: " << provider.age << endl;
    return output;
  }

  friend istream &operator>>(istream &input, Provider &provider) {
    cout << "email: ";
    input >> provider.email;
    cout << "password: ";
    input >> provider.password;
    cout << "type: ";
    input >> provider.type;
    cout << "name: ";
    input >> provider.name;
    cout << "age: ";
    input >> provider.age;

    vector<Error> errors;

    provider.create({
        new StringFieldORM("email", provider.email),
        new StringFieldORM("type", provider.type),
        new StringFieldORM("name", provider.name),
        new StringFieldORM("password", provider.password),
        new IntFieldORM("age", provider.age),
    }, errors);

    for (auto &errors : errors) {
        cout << errors.getMessage() << endl;
    }

    return input;
  }

  void sayHello() override { cout << "Hello i am provider" << endl; }
};
