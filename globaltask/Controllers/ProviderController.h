#pragma once

#include "IController.h"
#include "../Views/ProviderView.h"

class ProviderController : public IController<ProviderView> {
 public:
    ProviderController();

    void run() override;

    void goMain();

    void goAuthentication();
};
