#pragma once
#include "./database/db.h"
#include "../utils/Observer.h"

class ProductType : public BaseORM, public Observable {
public:
  ProductType(initializer_list<ASchemaField *> extendedFields = {},
              const char *type = typeid(ProductType).name())
      : BaseORM(new Schema({
            (new SchemaField<StringFieldORM>("_id"))
                                ->autoGenerate(true)
                                ->required(true)
                                ->unique(true),
            (new SchemaField<StringFieldORM>("type"))
                                ->required(true)
                                ->unique(true)
                                },
                           extendedFields),
                type) {}
};
