#pragma once

#include "UserModel.h"

class ProviderModel : public UserModel {
 public:
  ProviderModel() : UserModel({
    (new SchemaFuild<StringFieldORM>("productType"))->required(true)
    ->unique(true),
  }) {}
};
