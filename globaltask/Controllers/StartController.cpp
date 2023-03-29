#include "StartController.h"
#include "ProviderController.h"
#include "EmployerController.h"
#include "FirstLabController.h"

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


void StartController::onSelectFirstLab() {
    FirstLabController *firstLabController = new FirstLabController();
    firstLabController->run();
    delete firstLabController;
}
