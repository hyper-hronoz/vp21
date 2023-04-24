#include "AuthenticationController.h"
#include "ProviderController.h"
#include "StartController.h"

#include "../Views/AuthEmployerLoginView.h"
#include "../Views/AuthEmployerSignUpView.h"
#include "../Views/AuthProviderLoginView.h"
#include "../Views/AuthProviderSignUpView.h"

void AuthenticationController::loginEmployer() {
  AuthEmployerLoginView view;
  StringFieldORM password("password", view.getPassword());
  StringFieldORM *login = new StringFieldORM("email", view.getLogin());
  Employer newEmployer = this->employer.findOne<StringFieldORM>(login);
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

  employer.create({email, title, name, password, age}, errors);

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
  StringFieldORM *type = new StringFieldORM("type");
  StringFieldORM *name = new StringFieldORM("name");
  StringFieldORM *password = new StringFieldORM("password");
  IntFieldORM *age = new IntFieldORM("age");

  cout << "Email: ";
  cin >> email;
  cout << "Type: ";
  cin >> type;
  cout << "Name: ";
  cin >> name;
  cout << "Password: ";
  cin >> password;
  cout << "Age: ";
  cin >> age;

  provider.create({email, type, name, password, age}, errors);

  for (auto &errors : errors) {
    cout << errors.getMessage() << endl;
  }

  if (errors.size() > 0) {
    cout << "Ошибка регистрации" << endl;
    return;
  }
  cout << "Поставщиек успешно зарегистрирован" << endl;
}

void AuthenticationController::goBack() { StartController(); }
