#pragma once

#include "Menu/Menu.h"
#include "../Controllers/IController.h"

template<class VIEW>
class AView {
 protected:
     Menu *menu = new Menu();
     IController<VIEW> *controller;
     MenuItemFactory* menuItemFactory = new MenuItemFactory();

 public:
    explicit AView(IController<VIEW>* controller) {
        this->controller = controller;
    }

    ~AView() {
        delete this->menuItemFactory;
        delete this->controller;
        delete this->menu;
    }

    virtual void display() = 0;
};
