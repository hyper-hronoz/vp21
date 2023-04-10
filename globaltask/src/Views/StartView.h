#pragma once

#include "BaseView.h"

class StartView : public BaseView {
 public:
  StartView() {
    this->menu = Menu("Menu title");
  }

  void display() override {
    this->menu.awaitUserInput();
  }
};
