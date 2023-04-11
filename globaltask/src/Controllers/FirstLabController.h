#pragma once

#include "../Views/FirstLabView.h"

class FirstLabController {
 private:
  FirstLabView *view = new FirstLabView();

  void goBack();

 public:
  FirstLabController() {
    MenuItemFactory menuItemFactory{};

    this->view->getMenu()->append(menuItemFactory.create(
        "Поздороваться", [=]() { this->view->sayHello(); }));

    this->view->getMenu()->append(menuItemFactory.create(
        "Вычеслить корень 25", [=]() { this->view->calculateSqureRoot(); }));

    this->view->getMenu()->append(
        menuItemFactory.create("Изобразить картинку псевдографикой!",
                               [=]() { this->view->printGraphics(); }));

    this->view->getMenu()->append(
        menuItemFactory.create("Вернуться",
                               [=]() { this->goBack(); }));
    this->view->display();
  }

  ~FirstLabController() {
      delete this->view;
  }
};
