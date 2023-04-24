#pragma once

#include "string"
#include "AuthBaseView.h"

class AuthBaseViewSignUp : public AuthBaseView {
 protected:
  std::string passwordConfirmation;

 public:
  std::string getPasswordConfirmation() {
    return this->passwordConfirmation;
  }
};
