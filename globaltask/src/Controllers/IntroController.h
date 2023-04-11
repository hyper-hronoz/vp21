#pragma once

#include "../Views/IntoView.h"

class IntroController {
 private:
  IntroView *view = new IntroView();

  void goBack();

 public:
  IntroController() {
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

  ~IntroController() {
      delete this->view;
  }
};
