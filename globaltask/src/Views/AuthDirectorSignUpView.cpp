#include "AuthDirectorSignUpView.h"

void AuthDirectorSignUpView::doSignUp() {
  std::cout << "---Provider signUp---" << std::endl;
  std::cout << "Input login: ";
  std::cin >> this->login;
  std::cout << "Input password: ";
  std::cin >> this->password;
  std::cout << "Confirm password: ";
  std::cin >> this->passwordConfirmation;
}

void AuthDirectorSignUpView::display() {
  this->doSignUp();
}
