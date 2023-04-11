#pragma once
#include "User.h"
#include "vector"

class Provider : public User {
protected:
  std::string type;

  void update(vector<AFieldORM *> fields) {
    if (!fields.size()) {
      return;
    }
    this->id = HardCast<StringFieldORM>(fields, "_id")->getValue();
    this->type = HardCast<StringFieldORM>(fields, "type")->getValue();
    this->name = HardCast<StringFieldORM>(fields, "name")->getValue();
    this->email = HardCast<StringFieldORM>(fields, "email")->getValue();
    this->age = HardCast<IntFieldORM>(fields, "age")->getValue();
    this->password = HardCast<StringFieldORM>(fields, "password")->getValue(); }
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
    output << "password: " << provider.password << endl;
    return output;
  }

  friend istream &operator>>(istream &input, Provider &provider) {
    vector<Error> errors;

    StringFieldORM *email = new StringFieldORM("email", provider.email);
    StringFieldORM *type = new StringFieldORM("type", provider.type);
    StringFieldORM *name = new StringFieldORM("name", provider.name);
    StringFieldORM *password =
        new StringFieldORM("password", provider.password);
    IntFieldORM *age = new IntFieldORM("age", provider.age);

    cout << "Email: "; cin >> email;
    cout << "Type: "; cin >> type;
    cout << "Name: "; cin >> name;
    cout << "Password: "; cin >> password;
    cout << "Age: "; cin >> age;

    provider.create({email, type, name, password, age}, errors);

    for (auto &errors : errors) {
      cout << errors.getMessage() << endl;
    }

    return input;
  }

  void sayHello() override { cout << "Hello i am provider" << endl; }
};
