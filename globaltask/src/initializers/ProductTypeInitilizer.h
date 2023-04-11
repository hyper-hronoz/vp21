#pragma once

#include "vector"
#include "../Models/ProductType.h"

class ProductTypeInitilizer {
 private:
  ProductType model;

 public:
  void initilizeProductTypes() {
    vector<Error> errors;

    model.create({new StringFieldORM("type", "toys")}, errors);
    model.create({new StringFieldORM("type", "meal")}, errors);
    model.create({new StringFieldORM("type", "office")}, errors);
    model.create({new StringFieldORM("type", "animal")}, errors);

    for (auto &error : errors) {
      if (error.getErrorType() != ERROR_TYPES::SAME_ENTRY) {
        std::cout << error.getMessage() << std::endl;
      }
    }
  }
};
