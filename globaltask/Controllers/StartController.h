#pragma once
#include "IController.h"
#include "../Views/StartView.h"
#include "EmployerController.h"
#include "ProviderController.h"

class StartController : public IController {
 private:
    StartView *startView = new StartView(this); 

 public:
    void run() override;

    StartController() {
        this->run();
    }

    ~StartController() {
        delete startView;
    }

    void onSelectProvider();

    void onSelectEmployer();
};
