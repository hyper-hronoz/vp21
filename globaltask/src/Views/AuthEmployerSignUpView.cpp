#include "AuthEmployerSignUpView.h"

void AuthEmployerSignUpView::doSignUp() {
  std::cout << "---Employer signUp---" << std::endl;
  std::cout << "Input login: ";
  std::cin >> this->login;
  std::cout << "Input password: ";
  std::cin >> this->password;
  std::cout << "Confirm password: ";
  std::cin >> this->passwordConfirmation;
}

void AuthEmployerSignUpView::display() {
  this->doSignUp();
}
