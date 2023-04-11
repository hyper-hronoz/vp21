#pragma once

#include "BaseView.h"

class StartView : public BaseView {
 public:
  StartView() {
    this->menu = Menu("---Выберите лабу---");
  }

  void display() override;
};
