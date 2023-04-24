#pragma once

#include "string"
#include "AuthBaseView.h"

class AuthEmployerLoginView : public AuthBaseView {
  void doLogin();

public:
  AuthEmployerLoginView() {
    this->display();
  }

  void display() override;
};
