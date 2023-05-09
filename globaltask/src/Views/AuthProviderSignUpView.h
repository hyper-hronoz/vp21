#pragma once

#include "AuthBaseViewSignUp.h"

class AuthProviderSignUpView : public AuthBaseViewSignUp {
 private:
  void doSignUp();

 public:
  AuthProviderSignUpView() {}

  void display() override;
};


