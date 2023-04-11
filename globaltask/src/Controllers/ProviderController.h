#pragma once

#include "../Views/ProviderView.h"
#include "../Models/ProductType.h"

class ProviderController {
private:
  ProviderView *view = new ProviderView();
  ProductType model;

  void getAllProductTypes();

  void goBack();

public:
  ProviderController() {
    MenuItemFactory factory{};

    this->view->getMenu()->append(factory.create("Напечатать типы продуктов", [=]() {
        this->getAllProductTypes();
    }));

    this->view->getMenu()->append(factory.create("На главную", [=]() {
        this->goBack();
    }));

    this->view->display();
  }

  ~ProviderController() { delete view; }
};
