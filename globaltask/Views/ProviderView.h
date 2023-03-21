#pragma once
#include "AView.h"
#include "./Menu/Menu.h"

class ProviderView : public AView<ProviderView> {
 public:
    explicit ProviderView(IController<ProviderView>* controller) :
        AView<ProviderView>(controller) {}

    void display() override;

 private:
    void createProviderMenu();
};
