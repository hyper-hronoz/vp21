#pragma once

#include "../Controllers/IController.h"

class AView {
 protected:
     IController *controller;

 public:
    AView(IController* controller) {
        this->controller = controller; 
    }
    virtual void display() = 0;
};
