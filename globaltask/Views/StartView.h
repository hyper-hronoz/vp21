#pragma once

#include "BaseView.h"
#include <math.h>

class StartView : public BaseView {
 private:
  Menu menu;
  MenuItemFactory menuItemFactory;

 public:
  StartView();
  void display() override;
};
