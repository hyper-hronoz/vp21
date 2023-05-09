#pragma once

#include "../Views/DirectorView.h"

#include "../Models/ProductTransaction.h"
#include "../Models/Product.h"
#include "../Models/Provider.h"

class DirectorController {
private:
  DirectorView *view = new DirectorView();
  ProductTransaction productTransactionModel;
  Product productModel;
  Provider providerModel;

  void onSelectSuppliedProducts(); 

public:
  DirectorController() {}

  ~DirectorController() { delete this->view; }
};
