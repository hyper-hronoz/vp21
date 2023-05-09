#pragma once
#include "User.h"
#include "string"
#include "vector"

class Director : public User {
protected:
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
    } catch (std::exception &e) {
      std::cout << "Bad cast Provider, not enought data" << std::endl;
    }
  }

public:
  Director(vector<AFieldORM *> fields = {}) : User({}, typeid(this).name()) {
    this->update(fields);
  }

  friend ostream &operator<<(ostream &output, const Director &provider) {
    output << "_id: " << provider.id << endl;
    output << "email: " << provider.email << endl;
    output << "name: " << provider.name << endl;
    output << "age: " << provider.age << endl;
    return output;
  }

  void operator=(vector<AFieldORM *> fields) { this->update(fields); }

  friend istream &operator>>(istream &input, Director &provider) {
    return input;
  }

  void sayHello() override { cout << "Hello i am provider" << endl; }
};
