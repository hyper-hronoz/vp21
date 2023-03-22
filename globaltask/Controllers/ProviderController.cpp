#include "ProviderController.h"
#include "StartController.h"

#include "../Models/ProviderModel.h"

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

void ProviderController::goSignUp() {
    ProviderModel* providerModel = new ProviderModel();

    providerModel->setLogin("hronoz")->setName("Vladislav")->setSername("Moryakov")->setPassword("77884488");

    providerModel->signUp();

    delete providerModel;
}
