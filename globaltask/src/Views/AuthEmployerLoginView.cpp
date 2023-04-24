#include "AuthEmployerLoginView.h"

void AuthEmployerLoginView::doLogin() {
  std::cout << "---Employer login---" << std::endl;
  std::cout << "Input login: ";
  std::cin >> this->login;
  std::cout << "Input password: ";
  std::cin >> this->password;
}

void AuthEmployerLoginView::display() {
  this->doLogin();
}
