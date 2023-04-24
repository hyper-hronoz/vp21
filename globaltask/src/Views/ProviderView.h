#pragma once

#include "BaseView.h"
#include "../Models/ProductType.h"

class ProviderView : public BaseView {
 public:
  ProviderView() {
    this->menu = Menu("---Provider menu---");
  }

  void display() override;
};
