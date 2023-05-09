#pragma once

#include "BaseView.h"
#include "../Models/Employer.h"

class EmployerView : public BaseView {

public:
  EmployerView() { this->menu = Menu("---Employer menu---"); }

  void printEmployer(Employer *employer) { cout << *employer << endl; }

  void display() override;
};
