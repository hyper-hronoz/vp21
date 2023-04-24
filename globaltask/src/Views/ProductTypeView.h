#pragma once

#include "../Models/ProductType.h"
#include "../utils/Observer.h"

class ProductTypeView : public Observer {
private:
  ProductType model;

public:
  ProductTypeView(ProductType model) {
    this->model = model;
    this->model.addObserver(this);
  }

  void printModel();

  void update() override;
};
