#pragma once

#include "../Models/Employer.h"
#include "../Models/Provider.h"
#include "../Models/Director.h"

#include "../Models/ProductType.h"

#include "../Views/AuthenticationView.h"

class AuthenticationController {
private:
  AuthenticationView *view = new AuthenticationView();
  Employer employerModel;
  Provider providerModel;
  Director directorModel;

  void signUpEmployer();

  void signUpProvider();

  void loginEmployer();

  void loginProvider();

  void goBack();

  void loginDirector();

  void signUpDirector();

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
        "Войти как крыша", [=]() { this->loginDirector(); }));

    this->view->getMenu()->append(menuItemFactory.create(
        "Зарегестрировать крышу", [=]() { this->signUpDirector(); }));

    this->view->getMenu()->append(menuItemFactory.create(
        "Вернуться", [=]() { this->goBack(); }));

    this->view->display();
  }
};
