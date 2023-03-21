#include "StartController.h"
#include "ProviderController.h"
#include "EmployerController.h"

StartController::StartController() {
    this->view = new StartView(this);
    this->run();
}

void StartController::run() {
    this->view->display();
}

void StartController::onSelectProvider() {
    ProviderController *providerController = new ProviderController();
    providerController->run();
    delete providerController;
}

void StartController::onSelectEmployer() {
    EmployerController *employerController = new EmployerController();
    employerController->run();
    delete employerController;
}

