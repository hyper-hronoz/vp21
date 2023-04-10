#include "StartView.h"

StartView::StartView() {
  this->menu = Menu("---First lab menu---");

  this->menu.append(this->menuItemFactory.create("Вычеслить корень 25", []() {
    std::cout << "Полезная логика!!!!!!!!" << std::endl;
    std::cout << sqrt(25) << std::endl;
  }));

  this->menu.append(this->menuItemFactory.create("Поздороваться", []() {
    std::cout << "Вжжжжжжжжжжжж, Hello there! General Kenobi!" << std::endl;
  }));

  this->menu.append(
      this->menuItemFactory.create("Изобразить картинку псевдографикой!", []() {
        std::cout << "██╗  ██╗██████╗  ██████╗ ███╗   ██╗ ██████╗ ███████╗"
                  << "\n"
                     "██║  ██║██╔══██╗██╔═══██╗████╗  ██║██╔═══██╗╚══███╔╝"
                  << "\n"
                  << "███████║██████╔╝██║   ██║██╔██╗ ██║██║   ██║  ███╔╝ "
                  << "\n"
                  << "██╔══██║██╔══██╗██║   ██║██║╚██╗██║██║   ██║ ███╔╝  "
                  << "\n"
                  << "██║  ██║██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝███████╗"
                  << "\n"
                  << "╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝"
                  << std::endl;
      }));

  this->menu.awaitUserInput();
}
