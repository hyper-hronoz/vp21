#pragma once

#include "iostream"
#include "../Storage/Storage.h"
#include "../Observable.h"

class UserModel : public BaseORM, public Observervable {
 public:
  UserModel(initializer_list<ASchemaFuild*> extendedFuilds = {}) : BaseORM(Schema({
    (new SchemaFuild<StringFieldORM>("id"))->required(true),
    (new SchemaFuild<StringFieldORM>("email"))->required(true)->unique(true),
    (new SchemaFuild<StringFieldORM>("name"))->required(true)->unique(true),
    (new SchemaFuild<StringFieldORM>("sername"))->required(true)->unique(true),
    (new SchemaFuild<StringFieldORM>("login"))->required(true)->unique(true),
    (new SchemaFuild<StringFieldORM>("password"))->required(true)->unique(true),
    (new SchemaFuild<IntFieldORM>("age"))->required(true)->unique(true),
  }, extendedFuilds), typeid(this).name()) {}
};
