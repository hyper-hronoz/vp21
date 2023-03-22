#pragma once
#include "AView.h"
#include "./Menu/Menu.h"

class EmployerView : public AView<EmployerView> {
 public:
    explicit EmployerView(IController<EmployerView>* controller)
        : AView<EmployerView>(controller) {}

    void display() override;

 private:
    void createEmployerMenu();
};
