#include "AuthProviderLoginView.h"

void AuthProviderLoginView::doLogin() {
  std::cout << "---Provider login---" << std::endl;
  std::cout << "Input login: ";
  std::cin >> this->login;
  std::cout << "Input password: ";
  std::cin >> this->password;
}

void AuthProviderLoginView::display() { this->doLogin(); }
