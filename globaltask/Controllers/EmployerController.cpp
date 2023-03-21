#include "EmployerController.h"

EmployerController::EmployerController() {
    this->view = new EmployerView(this);
}

void EmployerController::run() {
    this->view->display();
}
