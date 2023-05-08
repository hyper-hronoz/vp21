#pragma once
#include "User.h"
#include "string"
#include "vector"

class Provider : public User {
protected:
  std::string productID;
  int amount;

  void update(vector<AFieldORM *> fields) {
    try {
      if (!fields.size()) {
        return;
      }
      this->id = HardCast<StringFieldORM>(fields, "_id")->getValue();
      this->age = HardCast<IntFieldORM>(fields, "age")->getValue();
      this->name = HardCast<StringFieldORM>(fields, "name")->getValue();
      this->email = HardCast<StringFieldORM>(fields, "email")->getValue();
      this->password = HardCast<StringFieldORM>(fields, "password")->getValue();
      this->amount = HardCast<IntFieldORM>(fields, "amount")->getValue();
      this->productID =
          HardCast<StringFieldORM>(fields, "productID")->getValue();
    } catch (std::exception &e) {
      std::cout << "Bad cast Provider, not enought data" << std::endl;
    }
  }

public:
  Provider(vector<AFieldORM *> fields = {})
      : User(
            {
                (new SchemaField<IntFieldORM>("amount"))->required(true),
                (new SchemaField<StringFieldORM>("productID"))->required(true),
            },
            typeid(this).name()) {
    this->update(fields);
  }

  int getProductsAmount() { return this->amount; }

  friend ostream &operator<<(ostream &output, const Provider &provider) {
    output << "_id: " << provider.id << endl;
    output << "email: " << provider.email << endl;
    output << "amount: " << provider.amount << endl;
    output << "name: " << provider.name << endl;
    output << "age: " << provider.age << endl;
    output << "productID: " << provider.productID << endl;
    return output;
  }

  void operator=(vector<AFieldORM *> fields) { this->update(fields); }

  friend istream &operator>>(istream &input, Provider &provider) {
    return input;
  }

  void sayHello() override { cout << "Hello i am provider" << endl; }
};
