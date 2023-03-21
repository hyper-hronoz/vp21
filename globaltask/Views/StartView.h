#pragma once
#include "iostream"
#include "AView.h"

class StartView : public AView<StartView> {
 public:
    explicit StartView(IController<StartView>* controller)
        : AView<StartView>(controller) {}

    void display() override;

 private:
    void createStartMenu();
};
