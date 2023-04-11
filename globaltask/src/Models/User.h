#pragma once
#include "./database/db.h"
#include "../utils/Observer.h"

class User : public BaseORM, public Observable {
 protected:
   std::string id;
   std::string email;
   int age;
   std::string name;
   std::string password;

public:
  User(initializer_list<ASchemaField *> extendedFields = {},
       const char *type = typeid(User).name())
      : BaseORM(
            new Schema(
                {(new SchemaField<StringFieldORM>("_id"))
                     ->required(true)->autoGenerate(true)->unique(true),
                 (new SchemaField<StringFieldORM>("email"))
                     ->required(true)
                     ->unique(true),
                 (new SchemaField<IntFieldORM>("age"))->required(true),
                 (new SchemaField<StringFieldORM>("name"))->required(true),
                 (new SchemaField<StringFieldORM>("password"))->required(true)},
                extendedFields),
            type) {}

  friend ostream &operator<<(ostream &output, const User &product) {
    output << "_id: " << product.id << endl;
    output << "name: " << product.name << endl;
    output << "email: " << product.email << endl;
    output << "age: " << product.age << endl;
    output << "password: " << product.password << endl;
    return output;
  }

  virtual void sayHello() = 0;
};
