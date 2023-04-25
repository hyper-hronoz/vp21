#pragma once
#include "User.h"
#include "vector"

class Provider : public User {
protected:
  std::string type;
  int amount;

  void update(vector<AFieldORM *> fields) {
    if (!fields.size()) {
      return;
    }
    this->id = HardCast<StringFieldORM>(fields, "_id")->getValue();
    this->type = HardCast<StringFieldORM>(fields, "type")->getValue();
    this->amount = HardCast<IntFieldORM>(fields, "amount")->getValue();
    this->name = HardCast<StringFieldORM>(fields, "name")->getValue();
    this->email = HardCast<StringFieldORM>(fields, "email")->getValue();
    this->age = HardCast<IntFieldORM>(fields, "age")->getValue();
    this->password = HardCast<StringFieldORM>(fields, "password")->getValue(); }
public:
  Provider(vector<AFieldORM *> fields = {})
      : User(
            {
                (new SchemaField<StringFieldORM>("type"))->required(true),
                (new SchemaField<IntFieldORM>("amount"))->required(true),
            },
            typeid(this).name()) {
    this->update(fields);
  }

  int getProductsAmount() {
    return this->amount;
  }

  friend ostream &operator<<(ostream &output, const Provider &provider) {
    output << "_id: " << provider.id << endl;
    output << "email: " << provider.email << endl;
    output << "type: " << provider.type << endl;
    output << "amount: " << provider.amount << endl;
    output << "name: " << provider.name << endl;
    output << "age: " << provider.age << endl;
    // output << "password: " << provider.password << endl;
    return output;
  }

  friend istream &operator>>(istream &input, Provider &provider) {
    return input;
  }

  void sayHello() override { cout << "Hello i am provider" << endl; }
};
