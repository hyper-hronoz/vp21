#pragma once
#include "IController.h"
#include "../Views/StartView.h"

#include "EmployerController.h"
#include "ProviderController.h"

class StartController : public IController<StartView> {
 public:
    void run() override;

    StartController();

    void onSelectProvider();

    void onSelectEmployer();

    void onSelectFirstLab();
};
