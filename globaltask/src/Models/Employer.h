#pragma once

#include "User.h"
#include "vector"

class Employer : public User {
private:
  std::string title;

  void update(vector<AFieldORM *> fields) {
    if (!fields.size()) {
      return;
    }
    this->id = HardCast<StringFieldORM>(fields, "_id")->getValue();
    this->title = HardCast<StringFieldORM>(fields, "title")->getValue();
    this->name = HardCast<StringFieldORM>(fields, "name")->getValue();
    this->email = HardCast<StringFieldORM>(fields, "email")->getValue();
    this->password = HardCast<StringFieldORM>(fields, "password")->getValue();
    this->age = HardCast<IntFieldORM>(fields, "age")->getValue();
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

  friend istream &operator>>(istream &input, Employer &employer) {
    vector<Error> errors;

    StringFieldORM *email = new StringFieldORM("email", employer.email);
    StringFieldORM *title = new StringFieldORM("title", employer.title);
    StringFieldORM *name = new StringFieldORM("name", employer.name);
    StringFieldORM *password =
        new StringFieldORM("password", employer.password);
    IntFieldORM *age = new IntFieldORM("age", employer.age);

    cout << "Email: ";
    cin >> email;
    cout << "Job title: ";
    cin >> title;
    cout << "Name: ";
    cin >> name;
    cout << "Password: ";
    cin >> password;
    cout << "Age: ";
    cin >> age;

    employer.create({email, title, name, password, age}, errors);

    for (auto &errors : errors) {
      cout << errors.getMessage() << endl;
    }

    return input;
  }
};
