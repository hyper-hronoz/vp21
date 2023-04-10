#pragma once

#include "./Menu/Menu.h"

class BaseView {
protected:
  Menu menu;

public:
  Menu* getMenu() {
    return &this->menu;
  }
  virtual void display() = 0;
};
