#pragma once

#include "BaseView.h"

class DirectorView : public BaseView {
public:
  DirectorView() {
    this->menu = Menu("---Director menu---");
  }

  void display() override;
};
