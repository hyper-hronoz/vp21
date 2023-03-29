#pragma once
#include "AView.h"
#include "./Menu/Menu.h"

class FirstLabView : public AView<FirstLabView> {
 public:
    explicit FirstLabView(IController<FirstLabView>* controller)
        : AView<FirstLabView>(controller) {}

    void display() override;

 private:
    void createFirstLabMenu();
};
