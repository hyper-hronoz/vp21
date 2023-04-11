#include "AuthenticationController.h"
#include "ProviderController.h"
#include "StartController.h"

void AuthenticationController::loginEmployer() {
  StringFieldORM password("password");
  StringFieldORM *login = new StringFieldORM("email");
  cout << "Input login: ";
  cin >> login;
  cout << "Input password: ";
  cin >> &password;
  Employer newEmployer = this->employer.findOne<StringFieldORM>(login);
  cout << newEmployer << endl;
  if (newEmployer.getEmail() == login->getValue() &&
      password.getValue() == newEmployer.getPassword()) {
    cout << "Login successfull" << endl;
  } else {
    cout << "Login is not successfull" << endl;
    cout << "Wrong login or password" << endl;
  }
}

void AuthenticationController::loginProvider() {
  StringFieldORM password("password");
  StringFieldORM *login = new StringFieldORM("email");
  cout << "Input login: ";
  cin >> login;
  cout << "Input password: ";
  cin >> &password;
  Provider newProvider = this->provider.findOne<StringFieldORM>(login);
  if (newProvider.getEmail() == login->getValue() &&
      password.getValue() == newProvider.getPassword()) {
    cout << "Login successfull" << endl;
    ProviderController();
  } else {
    cout << "Login is not successfull" << endl;
    cout << "Wrong login or password" << endl;
  }
}

void AuthenticationController::signUpEmployer() {
  cin >> this->employer;
  cout << "Сотрудник успешно зарегистрирован" << endl;
}

void AuthenticationController::signUpProvider() {
  cin >> this->provider;
  cout << "Поставщик успешно зарегистрирован" << endl;
}

void AuthenticationController::goBack() { StartController(); }
