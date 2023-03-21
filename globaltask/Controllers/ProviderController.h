#pragma once

#include "IController.h"
#include "../Views/ProviderView.h"
#include "StartController.h"
#include "AuthenticationController.h"

class ProviderController : public IController<ProviderView> {
 public:
    ProviderController() {
        this->view = new ProviderView(this);
    }

    void run() override;

    void goMain() {
        // StartController* startController = new StartController();
        // startController->run();
        // delete startController;
    }

    void goAuthentication() {
        // AuthenticationController* authenticationController = new AuthenticationController();
        // delete authenticationController;
    }
};
