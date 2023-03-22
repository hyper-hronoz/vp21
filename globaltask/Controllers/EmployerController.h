#pragma once

#include "IController.h"
#include "../Views/EmployerView.h"

class EmployerController : public IController<EmployerView> {
 public:
    EmployerController();

    void run() override;

    void goMain();

    void goSignUp();
};
