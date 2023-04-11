#pragma once
#include "../utils/Observer.h"
#include "./database/db.h"
#include <iostream>

class Product : public BaseORM, public Observable {
private:
  std::string id;
  std::string type;
  std::string name;
  int price;
  int amount;

  void update(vector<AFieldORM *> fields) {
    if (!fields.size()) {
      return;
    }
    this->id = HardCast<StringFieldORM>(fields, "_id")->getValue();
    this->name = HardCast<StringFieldORM>(fields, "name")->getValue();
    this->type = HardCast<StringFieldORM>(fields, "type")->getValue();
    this->price = HardCast<IntFieldORM>(fields, "price")->getValue();
    this->amount = HardCast<IntFieldORM>(fields, "amount")->getValue();
  }

public:
  Product(vector<AFieldORM *> fields = {},
          initializer_list<ASchemaField *> extendedFields = {},
          const char *type = typeid(Product).name())
      : BaseORM(new Schema(
                    {(new SchemaField<StringFieldORM>("_id"))
                         ->required(true)
                         ->autoGenerate(true)
                         ->unique(true),
                     (new SchemaField<StringFieldORM>("type"))->required(true),
                     (new SchemaField<StringFieldORM>("name"))
                         ->required(true)
                         ->unique(true),
                     (new SchemaField<IntFieldORM>("price"))->required(true),
                     (new SchemaField<IntFieldORM>("amount"))->required(true)},
                    extendedFields),
                type) {
    this->update(fields);
  }

  void operator=(vector<AFieldORM *> fields) { this->update(fields); }

  friend ostream &operator<<(ostream &output, const Product &product) {
    output << "_id: " << product.id << endl;
    output << "name: " << product.name << endl;
    output << "type: " << product.type << endl;
    output << "price: " << product.price << endl;
    output << "amount: " << product.amount << endl;
    return output;
  }

  friend istream &operator>>(istream &input, Product &product) {
    cout << "Не несет полезной нагрузки" << endl;
    return input;
  }
};
