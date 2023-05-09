#pragma once

#include "./Storage/Storage.h"
#include "Observable.h"

class ProviderModel : public BaseORM, public Observervable {
 public:
  ProviderModel() : BaseORM(Schema{
    (new SchemaFuild<StringFieldORM>("name"))->required(true),
    (new SchemaFuild<StringFieldORM>("type"))->required(true),
    (new SchemaFuild<IntFieldORM>("price"))->required(true),
    (new SchemaFuild<IntFieldORM>("amount"))->required(true),
  }, typeid(this).name()) {}
};
