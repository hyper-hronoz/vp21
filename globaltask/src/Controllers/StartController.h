#pragma once

#include "../Views/StartView.h"

class StartController {
 private:
  StartView *view = new StartView();

  void onSelectIntro();

  void onSelectAuth();

  void onSelectThirdLab();

 public:
  StartController() {
    MenuItemFactory menuItemFactory{};

    view->getMenu()->append(menuItemFactory.create("Узнать о заводе", [this] () {
      this->onSelectIntro();
    }));

    view->getMenu()->append(menuItemFactory.create("Авторизироваться", [this] () {
      this->onSelectAuth();
    }));

    view->display();
  }

  ~StartController() {
    delete view;
  }
};
