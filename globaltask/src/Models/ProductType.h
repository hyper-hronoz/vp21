#pragma once
#include "../utils/Observer.h"
#include "./database/db.h"
#include "string"
#include "vector"

class ProductType : public BaseORM, public Observable {
private:
  string type;

  void update(vector<AFieldORM *> fields) {
    if (fields.size() == 0) {
      return;
    }
    this->type = HardCast<StringFieldORM>(fields, "type")->getValue();
  }

public:
  ProductType(vector<AFieldORM *> fields = {},
              initializer_list<ASchemaField *> extendedFields = {},
              const char *type = typeid(ProductType).name())
      : BaseORM(new Schema({(new SchemaField<StringFieldORM>("_id"))
                                ->autoGenerate(true)
                                ->required(true)
                                ->unique(true),
                            (new SchemaField<StringFieldORM>("type"))
                                ->required(true)
                                ->unique(true)},
                           extendedFields),
                type) {
    this->update(fields);
  }

  std::string getType() { return this->type; }

  void operator=(vector<AFieldORM *> fields) { this->update(fields); }

  friend ostream &operator<<(ostream &output, const ProductType &pt) {
    output << pt.type;
    return output;
  }

  friend bool operator>(ProductType &pt1, ProductType &pt2) {
    return pt1.getType() > pt2.getType();
  }

  friend bool operator<(ProductType &pt1, ProductType &pt2) {
    return pt1.getType() < pt2.getType();
  }
};
