#include "EmployerController.h"
#include "StartController.h"
#include "AuthenticationController.h"

EmployerController::EmployerController() {
    this->view = new EmployerView(this);
}

void EmployerController::run() {
    this->view->display();
}

void EmployerController::goMain() {
    StartController* startController = new StartController();
    startController->run();
    delete startController;
}

void EmployerController::goAuthentication() {
    AuthenticationController* authenticationController = new AuthenticationController();
    delete authenticationController;
}
