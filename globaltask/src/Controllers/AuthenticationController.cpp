#include "AuthenticationController.h"
#include "StartController.h"

void AuthenticationController::loginEmployer() {}

void AuthenticationController::loginProvider() {
  // StringFieldORM *login = new StringFieldORM("email");
  // StringFieldORM *password = new StringFieldORM("password");
  // cout << "Input login: ";
  // cin >> login;
  // cout << "Input password: ";
  // cin >> password; Provider provider = this->provider.findOne<StringFieldORM>({login});
}

void AuthenticationController::signUpEmployer() {
  // vector<Error> errors;
  //
  // this->employer.create({}, errors);
  //
  // if (errors.size() != 0) {
  //   for (auto &error : errors) {
  //     cout << error.getMessage() << std::endl;
  //   }
  // }
}

void AuthenticationController::signUpProvider() {
  vector<Error> errors;

  cin >> this->provider;
}

void AuthenticationController::goBack() {
  StartController(); 
}
