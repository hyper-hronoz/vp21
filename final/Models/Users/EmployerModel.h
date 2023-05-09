#pragma once

#include "UserModel.h"

class EmployerModel : public UserModel {
 public:
  EmployerModel() : UserModel({
    (new SchemaFuild<StringFieldORM>("jobTitle"))->required(true)->unique(true),
  }) {}
};
