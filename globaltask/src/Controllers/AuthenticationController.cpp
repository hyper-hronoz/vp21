#include "AuthenticationController.h"
#include "DirectorController.h"
#include "ProviderController.h"
#include "StartController.h"

#include "../Views/AuthDirectorLoginView.h"
#include "../Views/AuthDirectorSignUpView.h"
#include "../Views/AuthEmployerLoginView.h"
#include "../Views/AuthEmployerSignUpView.h"
#include "../Views/AuthProviderLoginView.h"
#include "../Views/AuthProviderSignUpView.h"

void AuthenticationController::loginDirector() {
  AuthDirectorLoginView view;
  StringFieldORM password("password", view.getPassword());
  StringFieldORM *login = new StringFieldORM("email", view.getLogin());
  Director *newDirector =
      new Director(this->directorModel.findOne<StringFieldORM>(login));
  if (newDirector->getEmail() == login->getValue() &&
      password.getValue() == newDirector->getPassword()) {
    cout << "Login successfull" << endl;
    DirectorController _(newDirector);
  } else {
    cout << "Login is not successfull" << endl;
    cout << "Wrong login or password" << endl;
  }
}

void AuthenticationController::signUpDirector() {
  vector<Error> errors;

  StringFieldORM *email = new StringFieldORM("email");
  StringFieldORM *name = new StringFieldORM("name");
  StringFieldORM *password = new StringFieldORM("password");
  IntFieldORM *age = new IntFieldORM("age");

  cout << "Email: ";
  cin >> email;
  cout << "Name: ";
  cin >> name;
  cout << "Password: ";
  cin >> password;
  cout << "Age: ";
  cin >> age;

  directorModel.create({email, name, password, age}, errors);

  if (errors.size() > 0) {
    cout << "Ошибка регистрации" << endl;
    for (auto &errors : errors) {
      cout << errors.getMessage() << endl;
    }
    return; }

  cout << "Директор успешно зарегистрирован" << endl;

  delete email;
  delete name;
  delete password;
  delete age;
}

void AuthenticationController::loginEmployer() {
  AuthEmployerLoginView view;
  StringFieldORM password("password", view.getPassword());
  StringFieldORM *login = new StringFieldORM("email", view.getLogin());
  Employer newEmployer = this->employerModel.findOne<StringFieldORM>(login);
  if (newEmployer.getEmail() == login->getValue() &&
      password.getValue() == newEmployer.getPassword()) {
    cout << "Login successfull" << endl;
  } else {
    cout << "Login is not successfull" << endl;
    cout << "Wrong login or password" << endl;
  }
}

void AuthenticationController::loginProvider() {
  AuthProviderLoginView view;
  StringFieldORM password("password", view.getPassword());
  StringFieldORM *login = new StringFieldORM("email", view.getLogin());
  Provider *newProvider =
      new Provider(this->providerModel.findOne<StringFieldORM>(login));
  if (newProvider->getEmail() == login->getValue() &&
      password.getValue() == newProvider->getPassword()) {
    cout << "Login successfull" << endl;
    ProviderController _(newProvider);
  } else {
    cout << "Login is not successfull" << endl;
    cout << "Wrong login or password" << endl;
  }
}

void AuthenticationController::signUpEmployer() {
  vector<Error> errors;

  StringFieldORM *email = new StringFieldORM("email");
  StringFieldORM *title = new StringFieldORM("title");
  StringFieldORM *name = new StringFieldORM("name");
  StringFieldORM *password = new StringFieldORM("password");
  IntFieldORM *age = new IntFieldORM("age");

  cout << "Email: ";
  cin >> email;
  cout << "Job title: ";
  cin >> title;
  cout << "Name: ";
  cin >> name;
  cout << "Password: ";
  cin >> password;
  cout << "Age: ";
  cin >> age;

  employerModel.create({email, title, name, password, age}, errors);

  for (auto &errors : errors) {
    cout << errors.getMessage() << endl;
  }

  if (errors.size() > 0) {
    cout << "Сотрудник не загистрирован, возникла ошибка" << endl;
    return;
  }
  cout << "Сотрудник успешно зарегистрирован" << endl;
}

void AuthenticationController::signUpProvider() {
  vector<Error> errors;

  StringFieldORM *email = new StringFieldORM("email");
  StringFieldORM *name = new StringFieldORM("name");
  StringFieldORM *password = new StringFieldORM("password");
  StringFieldORM *productID = new StringFieldORM("productID");
  IntFieldORM *age = new IntFieldORM("age");
  IntFieldORM *amount = new IntFieldORM("amount", 0);

  cout << "Email: ";
  cin >> email;
  cout << "Name: ";
  cin >> name;
  cout << "Password: ";
  cin >> password;
  cout << "Age: ";
  cin >> age;

  this->providerModel.create({email, name, password, age, productID, amount}, errors);

  if (errors.size() > 0) {
    cout << "Ошибка регистрации" << endl;
    for (auto &errors : errors) {
      cout << errors.getMessage() << endl;
    }
    return;
  }

  cout << "Поставщик успешно зарегистрирован" << endl;
}

void AuthenticationController::goBack() { StartController(); }
