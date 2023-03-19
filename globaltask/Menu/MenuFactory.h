#pragma once

#include "Menu.h"
#include "MenuItemFactory.h"

class MenuFactory {
 private:
    MenuItemFactory *menuItemFactory = new MenuItemFactory();

 public:
    Menu* getStartMenu();
    Menu* getProviderMenu();
    Menu* getEmployersMenu();

    ~MenuFactory();
};
