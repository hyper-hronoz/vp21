#pragma once

#include "BaseView.h"

class AuthenticationView : public BaseView {
 public:
  AuthenticationView() {
    this->menu = Menu("---Лаба 2 выберите дейстиве---");
  }

  void display() override;
};
