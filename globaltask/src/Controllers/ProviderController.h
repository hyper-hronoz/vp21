#pragma once

#include "../Models/ProductType.h"
#include "../Models/Provider.h"
#include "../Views/ProviderView.h"

class ProviderController {
private:
  ProviderView *view = new ProviderView();
  ProductType productModel;
  Provider *providerModel;

  void getAllProductTypes();

  void goBack();

  void provideProduct();

  void printInfo();

  void deleteAccount();

  void updateAccount();

  void refillProduct();

public:
  explicit ProviderController(Provider *provider) {
    this->providerModel = provider;
    MenuItemFactory factory{};

    this->view->getMenu()->append(factory.create(
        "Напечатать типы продуктов", [=]() { this->getAllProductTypes(); }));

    this->view->getMenu()->append(
        factory.create("Поставить продукт", [=]() { this->provideProduct(); }));

    this->view->getMenu()->append(factory.create(
        "Пополнение на складе", [=]() { this->refillProduct(); }));

    this->view->getMenu()->append(factory.create("Инофрмация о поставщике",
                                                 [=]() { this->printInfo(); }));

    this->view->getMenu()->append(factory.create(
        "Обновить все данные", [=]() { this->updateAccount(); }));

    this->view->getMenu()->append(factory.create("Удалить аккаунт", [=]() {
      char y;
      cout << "Do you wanna delete this account?(y/n): ";
      cin >> y;
      if (y == 'y') {
        this->deleteAccount();
      }
    }));

    this->view->getMenu()->append(
        factory.create("На главную", [=]() { this->goBack(); }));

    this->view->display();
  }

  ~ProviderController() { delete view; }
};
