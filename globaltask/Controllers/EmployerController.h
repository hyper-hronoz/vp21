#pragma once

#include "IController.h"
#include "../Views/EmployerView.h"
#include "AuthenticationController.h"
#include "StartController.h"

class EmployerController : public IController<EmployerView> {
 public:
    EmployerController();

    void run() override;

    void goMain() {
        StartController *startController = new StartController();
        delete startController;
    }

    void goAuthentication() {
        AuthenticationController* authenticationController = new AuthenticationController();
        delete authenticationController;
    }
};
