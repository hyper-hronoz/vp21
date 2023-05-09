#pragma once

#include "AuthBaseViewSignUp.h"

class AuthDirectorSignUpView : public AuthBaseViewSignUp {
private:
  void doSignUp();

public:
  AuthDirectorSignUpView() {}

  void display() override;
};
