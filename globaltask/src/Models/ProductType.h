#pragma once
#include "./database/db.h"

class ProductType : BaseORM {
public:
  ProductType(initializer_list<ASchemaField *> extendedFields = {},
              const char *type = typeid(ProductType).name())
      : BaseORM(new Schema({(new SchemaField<StringFieldORM>("type"))
                                ->required(true)
                                ->unique(true)},
                           extendedFields),
                type) {}
};
