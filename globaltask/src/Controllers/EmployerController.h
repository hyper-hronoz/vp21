#pragma once

#include "../Views/EmployerView.h"
#include "../Models/Employer.h"
#include "../Models/Product.h"
#include "../Models/Provider.h"
#include "../Models/ProductType.h"
#include "../Models/ProductionTransaction.h"

class EmployerController {
private:
  EmployerView *view = new EmployerView();
  Employer* employerModel;
  Product productModel;
  ProductType productTypeModel;
  ProductionTransaction productionTransactionModel;
  Provider providerModel;

  void goBack();

  void printInfo();

  void updateAccount();

  void produceProduct();

  void deleteAccount();

public:
  explicit EmployerController(Employer *employer) {
    this->employerModel = employer;

    MenuItemFactory factory{};

    this->view->getMenu()->append(factory.create(
        "Произвести продукт из исходников", [=]() { this->produceProduct(); }));

    this->view->getMenu()->append(factory.create(
        "Обновить все данные", [=]() { this->updateAccount(); }));

    this->view->getMenu()->append(factory.create(
        "Информация о пользователе", [=]() { this->printInfo(); }));


    this->view->getMenu()->append(
        factory.create("На главную", [=]() { this->goBack(); }));

    this->view->display();
  }

  ~EmployerController() { delete view; }
};
