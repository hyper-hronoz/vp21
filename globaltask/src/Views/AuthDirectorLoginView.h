#pragma once

#include "AuthBaseView.h"

class AuthDirectorLoginView : public AuthBaseView {
private:
  void doLogin();

public:
  AuthDirectorLoginView() { this->display(); }

  void display() override;
};
