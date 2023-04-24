#pragma once

#include "string"
#include "AuthBaseView.h"

class AuthProviderLoginView : public AuthBaseView {
 private:
  void doLogin();

 public:
  AuthProviderLoginView() {
   this->display();
  }

  void display() override;
};
