#pragma once

#include "IController.h"
#include "../Views/FirstLabView.h"

class FirstLabController : public IController<FirstLabView> {
 public:
    FirstLabController();

    void run() override;

    void goMain();

    void printHello();

    void printLogo();

    void printSqureRoot();
};
