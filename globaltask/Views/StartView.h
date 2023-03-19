#pragma once
#include "iostream"
#include "Menu/Menu.h"
#include "AView.h"

class StartView : public AView {
 private:
    MenuItemFactory* menuItemFactory = new MenuItemFactory();

 public:
    explicit StartView(IController* controller);

    ~StartView() {
        delete this->menuItemFactory;
    };
    
    void display() override;

 private:
    Menu* createStartMenu();
};
