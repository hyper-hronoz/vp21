#include "EmployerController.h"
#include "StartController.h"

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

void EmployerController::goSignUp() {
}
