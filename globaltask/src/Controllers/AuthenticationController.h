#pragma once

#include "../Models/Employer.h"
#include "../Models/Provider.h"
#include "../Models/ProductType.h"

#include "../Views/AuthenticationView.h"

class AuthenticationController {
private:
  AuthenticationView *view = new AuthenticationView();
  Employer employer;
  Provider provider;

  void signUpEmployer();

  void signUpProvider();

  void loginEmployer();

  void loginProvider();

  void goBack();

public:
  AuthenticationController() {
    MenuItemFactory menuItemFactory{};

    this->view->getMenu()->append(menuItemFactory.create(
        "Зарегистрировать сотрудника", [=]() { this->signUpEmployer(); }));

    this->view->getMenu()->append(menuItemFactory.create(
        "Загеристрировать поставщика", [=]() { this->signUpProvider(); }));

    this->view->getMenu()->append(menuItemFactory.create(
        "Войти как сотрудник", [=]() { this->loginEmployer(); }));

    this->view->getMenu()->append(menuItemFactory.create(
        "Войти как поставщик", [=]() { this->loginProvider(); }));

    this->view->getMenu()->append(menuItemFactory.create(
        "Вернуться", [=]() { this->goBack(); }));

    this->view->display();
  }
};
