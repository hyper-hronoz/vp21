#pragma once

#include "User.h"
#include "vector"

class Employer : public User {
private:
  std::string title;

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
    } catch (std::exception& e) {
      std::cout << "Bad cast Employer, not enought data" << std::endl;
    }
  }

public:
  Employer(vector<AFieldORM *> fields = {})
      : User(
            {
                (new SchemaField<StringFieldORM>("title"))->required(true),
            },
            typeid(this).name()) {
    this->update(fields);
  }

  void sayHello() override { cout << "Hello I am employer" << endl; }
};
