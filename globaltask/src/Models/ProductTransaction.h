#pragma once

#include "iostream"
#include "string"

#include "../utils/Observer.h"
#include "./database/db.h"

class ProductTransaction : public BaseORM, public Observable {
private:
  std::string id;
  std::string productID;
  std::string providerID;
  int amount;

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
      this->amount = HardCast<IntFieldORM>(fields, "amount")->getValue();
    } catch (std::exception &e) {
      std::cout << "Bad cast no enought data in product transaction "
                << std::endl;
    }
  }

public:
  ProductTransaction(vector<AFieldORM *> fields = {},
                     initializer_list<ASchemaField *> extendedFields = {},
                     const char *type = typeid(ProductTransaction).name())
      : BaseORM(
            new Schema(
                {(new SchemaField<StringFieldORM>("_id"))
                     ->required(true)
                     ->autoGenerate(true)
                     ->unique(true),
                 (new SchemaField<StringFieldORM>("productID"))->required(true),
                 (new SchemaField<StringFieldORM>("providerID"))
                     ->required(true),
                 (new SchemaField<IntFieldORM>("amount"))->required(true)},
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
    output << "amount: " << product.amount << endl;
    return output;
  }

  std::string getProductId() { return this->productID; }

  std::string getProviderId() { return this->providerID; }
};
