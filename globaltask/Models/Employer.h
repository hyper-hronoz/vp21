#pragma once

#include "User.h"

class Employer : public User {
public:
  Employer()
      : User(
            {
                (new SchemaField<StringFieldORM>("title"))->required(true),
            },
            typeid(this).name()) {}

  void showPass() {}
};