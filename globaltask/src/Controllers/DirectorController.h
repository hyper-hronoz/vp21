#pragma once

#include "../Views/DirectorView.h"

#include "../Models/Director.h"
#include "../Models/Product.h"
#include "../Models/ProductTransaction.h"
#include "../Models/ProductionTransaction.h"
#include "../Models/Provider.h"

class DirectorController {
private:
  DirectorView *view = new DirectorView();
  ProductTransaction productTransactionModel;
  Product productModel;
  Provider providerModel;
  ProductionTransaction productionTransactionModel;
  Director *directorModel;

  void onSelectSuppliedProducts();

  void onSelectSuppliedProductsEmployer();


  void deleteAccount();

  void goBack();

public:
  DirectorController(Director *directorModel) : directorModel(directorModel) {
    MenuItemFactory factory{};

    this->view->getMenu()->append(
        factory.create("Вывести историю транзакций поставщика", [=]() { this->onSelectSuppliedProducts(); }));

    this->view->getMenu()->append(
        factory.create("Вывести историю транзакций сотрудника", [=]() { this->onSelectSuppliedProductsEmployer(); }));

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

  ~DirectorController() { delete this->view; }
};
