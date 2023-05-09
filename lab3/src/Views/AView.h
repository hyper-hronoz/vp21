#pragma once

#include "iostream"

#include "./Menu/Menu.h"
#include "Observer.h"

class AView : public Observer {
 protected:
  Menu menu;
  MenuItemFactory menuItemFactory;

 public:
  virtual void update() = 0;
};
