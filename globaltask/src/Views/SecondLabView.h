#pragma once

#include "BaseView.h"

class SecondLabView : public BaseView {
 public:
  SecondLabView() {
    this->menu = Menu("---Лаба 2 выберите дейстиве---");
  }

  void display() override;
};
