#include "AuthDirectorLoginView.h" 

void AuthDirectorLoginView::doLogin() {
  std::cout << "---Director login---" << std::endl;
  std::cout << "Input login: ";
  std::cin >> this->login;
  std::cout << "Input password: ";
  std::cin >> this->password;
}

void AuthDirectorLoginView::display() { this->doLogin(); }
