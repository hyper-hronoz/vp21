#pragma once

#include<iostream>
#include "./Menu/Menu.h"

class BaseView {
 public:
  virtual void display() {
    std::cout << "Default view" << std::endl;
  }
};
