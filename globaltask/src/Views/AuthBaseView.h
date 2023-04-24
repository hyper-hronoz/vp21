#pragma once

#include "string"
#include "BaseView.h"

class AuthBaseView : public BaseView {
protected:
  std::string login;
  std::string password;

public:
  AuthBaseView() {}

  std::string getLogin() {
    return this->login;
  }

  std::string getPassword() {
    return this->password;
  }

  virtual void display() = 0;
};
