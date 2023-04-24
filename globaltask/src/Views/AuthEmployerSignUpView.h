#pragma once

#include "string"
#include "AuthBaseViewSignUp.h"

class AuthEmployerSignUpView : public AuthBaseViewSignUp {
 private:
  void doSignUp();

 public:
  AuthEmployerSignUpView() {}

  void display() override;
};
