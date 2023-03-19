#include "../Controllers/IController.h"

class AView {
 private:
     IController *controller;
 public:
    AView(IController* controller) {
        this->controller = controller; 
    }

    virtual void display() = 0;
};
