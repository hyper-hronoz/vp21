#pragma once

#include "User.h"
#include "vector"

class Employer : public User {
private:
  std::string title;
  std::string id;
  int amount;

  void update(vector<AFieldORM *> fields) {
    try {
      if (!fields.size()) {
        return;
      }
      this->id = HardCast<StringFieldORM>(fields, "_id")->getValue();
      this->title = HardCast<StringFieldORM>(fields, "title")->getValue();
      this->name = HardCast<StringFieldORM>(fields, "name")->getValue();
      this->email = HardCast<StringFieldORM>(fields, "email")->getValue();
      this->password = HardCast<StringFieldORM>(fields, "password")->getValue();
      this->age = HardCast<IntFieldORM>(fields, "age")->getValue();
      this->amount = HardCast<IntFieldORM>(fields, "amount")->getValue();
    } catch (std::exception &e) {
      std::cout << "Bad cast Employer, not enought data" << std::endl;
    }
  }

public:
  Employer(vector<AFieldORM *> fields = {})
      : User(
            {
                (new SchemaField<StringFieldORM>("title"))->required(true),
                (new SchemaField<IntFieldORM>("amount"))->required(true),
            },
            typeid(this).name()) {
    this->update(fields);
  }

  friend ostream &operator<<(ostream &output, const Employer &employer) {
    output << "_id: " << employer.id << endl;
    output << "name: " << employer.name << endl;
    output << "email: " << employer.email << endl;
    output << "amount: " << employer.amount << endl;
    output << "title: " << employer.title << endl;
    output << "age: " << employer.age << endl;
    return output;
  }

  void operator=(vector<AFieldORM *> fields) { this->update(fields); }

  std::string getId() { return this->id; }

  int getAmount() {
    return this->amount;
  }

  void sayHello() override { cout << "Hello I am employer" << endl; }
};
