#pragma once
#include "../utils/Observer.h"
#include "./database/db.h"
#include <iostream>

class ProductTransaction : public BaseORM, public Observable {
private:
  std::string id;
  std::string productID;
  std::string providerID;

  void update(vector<AFieldORM *> fields) {
    try {
      if (!fields.size()) {
        return;
      }
      this->id = HardCast<StringFieldORM>(fields, "_id")->getValue();
      this->productID =
          HardCast<StringFieldORM>(fields, "productID")->getValue();
      this->providerID =
          HardCast<StringFieldORM>(fields, "providerID")->getValue();
    } catch (std::exception &e) {
      std::cout << "Bad cast no enought data in product transaction "
                << std::endl;
    }
  }

public:
  ProductTransaction(vector<AFieldORM *> fields = {},
                     initializer_list<ASchemaField *> extendedFields = {},
                     const char *type = typeid(ProductTransaction).name())
      : BaseORM(new Schema(
                    {
                        (new SchemaField<StringFieldORM>("_id"))
                            ->required(true)
                            ->autoGenerate(true)
                            ->unique(true),
                        (new SchemaField<StringFieldORM>("productID"))
                            ->required(true),
                        (new SchemaField<StringFieldORM>("providerID"))
                            ->required(true)
                            ->unique(true),
                    },
                    extendedFields),
                type) {
    this->update(fields);
  }

  void operator=(vector<AFieldORM *> fields) { this->update(fields); }

  friend ostream &operator<<(ostream &output,
                             const ProductTransaction &product) {
    output << "_id: " << product.id << endl;
    output << "Product id: " << product.productID << endl;
    output << "Provider id: " << product.providerID << endl;
    return output;
  }
};
