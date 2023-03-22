#include "ProviderController.h"
#include "StartController.h"
#include "AuthenticationController.h"

ProviderController::ProviderController() {
    this->view = new ProviderView(this);
}

void ProviderController::run() {
    this->view->display();
}

void ProviderController::goMain() {
    StartController* startController = new StartController();
    startController->run();
    delete startController;
}

void ProviderController::goAuthentication() {
    AuthenticationController* authenticationController = new AuthenticationController();
    delete authenticationController;
}
