#pragma once

#include "../Views/StartView.h"

class StartController {
 private:
  StartView *view = new StartView();

  void onSelectFirstLab();

  void onSelectSecondLab();

  void onSelectThirdLab();

 public:
  StartController() {
    MenuItemFactory menuItemFactory{};

    view->getMenu()->append(menuItemFactory.create("Первая лаба", [this] () {
      this->onSelectFirstLab();
    }));

    view->getMenu()->append(menuItemFactory.create("Вторая лаба", [this] () {
      this->onSelectSecondLab();
    }));

    view->getMenu()->append(menuItemFactory.create("Третья лаба", [this] () {
      this->onSelectThirdLab();
    }));

    view->display();
  }

  ~StartController() {
    delete view;
  }
};
