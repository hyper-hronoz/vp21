#pragma once
#include "./database/db.h"

class User : public BaseORM {
public:
  User(initializer_list<ASchemaField *> extendedFields = {},
       const char *type = typeid(User).name())
      : BaseORM(
            new Schema(
                {(new SchemaField<StringFieldORM>("email"))
                     ->required(true)
                     ->unique(true),
                 (new SchemaField<IntFieldORM>("age"))->required(true),
                 (new SchemaField<StringFieldORM>("name"))->required(true),
                 (new SchemaField<StringFieldORM>("password"))->required(true)},
                extendedFields),
            type) {}

  virtual void showPass() = 0;
};
