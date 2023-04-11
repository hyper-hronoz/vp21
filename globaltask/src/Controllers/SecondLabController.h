#pragma once

#include "../Models/Employer.h"
#include "../Models/Provider.h"

#include "../Views/SecondLabView.h"

class SecondLabController {
private:
  SecondLabView *view = new SecondLabView();
  Employer employer;
  Provider provider;

  void signUpEmployer();

  void signUpProvider();

  void loginEmployer();

  void loginProvider();

public:
  SecondLabController() {
    MenuItemFactory menuItemFactory{};

    this->view->getMenu()->append(menuItemFactory.create(
        "Зарегистрировать сотрудника", [=]() { this->signUpEmployer(); }));

    this->view->getMenu()->append(menuItemFactory.create(
        "Загеристрировать поставщика", [=]() { this->signUpProvider(); }));

    this->view->getMenu()->append(menuItemFactory.create(
        "Войти как сотрудник", [=]() { this->loginEmployer(); }));

    this->view->getMenu()->append(menuItemFactory.create(
        "Войти как поставщик", [=]() { this->loginProvider(); }));

    this->view->display();
  }
};
