#pragma once

#include "../Models/ProductType.h"
#include "../Models/Provider.h"
#include "BaseView.h"

class ProviderView : public BaseView {

public:
  ProviderView() { this->menu = Menu("---Provider menu---"); }

  void printProvider(Provider *provider) { cout << *provider << endl; }

  void display() override;
};
