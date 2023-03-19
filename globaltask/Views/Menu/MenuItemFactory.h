#pragma once
#include "../Menu/MenuItem.h"

class MenuItemFactory {
 private:
    int id = 0;

 public:
    MenuItem* create(std::string title, std::function<void()> callback);
};
