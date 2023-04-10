#pragma once
#include "User.h"

class Provider : public User {
public:
  Provider()
      : User(
            {
                (new SchemaField<StringFieldORM>("product _id"))
                    ->required(true),
            },
            typeid(this).name()) {}

  void showPass() {}
};

