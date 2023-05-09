#pragma once

#include "iostream"
#include "string"

#include "../utils/Observer.h"
#include "./database/db.h"

class ProductionTransaction : public BaseORM, public Observable {
private:
  std::string id;
  std::string oldProductID;
  std::string providerID;
  std::string newProductID;
  int oldAmount;
  int newAmount;

  void update(vector<AFieldORM *> fields) {
    try {
      if (!fields.size()) {
        return;
      }
      this->id = HardCast<StringFieldORM>(fields, "_id")->getValue();
      this->oldProductID =
          HardCast<StringFieldORM>(fields, "oldProductID")->getValue();
      this->newProductID =
          HardCast<StringFieldORM>(fields, "newProductID")->getValue();
      this->providerID =
          HardCast<StringFieldORM>(fields, "providerID")->getValue();
      this->newAmount =
          HardCast<IntFieldORM>(fields, "newProductAmount")->getValue();
      this->oldAmount =
          HardCast<IntFieldORM>(fields, "oldProductAmount")->getValue();
    } catch (std::exception &e) {
      std::cout << "Bad cast no enought data in product transaction "
                << std::endl;
    }
  }

public:
  ProductionTransaction(vector<AFieldORM *> fields = {},
                        initializer_list<ASchemaField *> extendedFields = {},
                        const char *type = typeid(ProductionTransaction).name())
      : BaseORM(new Schema({(new SchemaField<StringFieldORM>("_id"))
                                ->required(true)
                                ->autoGenerate(true)
                                ->unique(true),
                            (new SchemaField<StringFieldORM>("oldProductID"))
                                ->required(true),
                            (new SchemaField<StringFieldORM>("newProductID"))
                                ->required(true),
                            (new SchemaField<StringFieldORM>("providerID"))
                                ->required(true),
                            (new SchemaField<IntFieldORM>("newProductAmount"))
                                ->required(true),
                            (new SchemaField<IntFieldORM>("oldProductAmount"))
                                ->required(true)},
                           extendedFields),
                type) {
    this->update(fields);
  }

  void operator=(vector<AFieldORM *> fields) { this->update(fields); }

  friend ostream &operator<<(ostream &output,
                             const ProductionTransaction &transaction) {
    output << "_id: " << transaction.id << endl;
    output << "Old product id: " << transaction.oldProductID << endl;
    output << "Provider id: " << transaction.providerID << endl;
    output << "New product id: " << transaction.newProductID << endl;
    output << "old product amount: " << transaction.oldAmount << endl;
    output << "new product amount: " << transaction.newAmount << endl;
    return output;
  }

  std::string getOldProductId() { return this->oldProductID; }

  std::string getNewProductId() { return this->newProductID; }

  int getNewProductAmount() { return this->newAmount; }

  int getOldProductAmount() { return this->oldAmount; }

  std::string getProviderId() { return this->providerID; }
};
