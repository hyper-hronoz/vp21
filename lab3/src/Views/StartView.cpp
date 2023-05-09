#include "StartView.h"

StartView::StartView() {
  this->menu.setTitle("---Welcome to the factory---");

  menu.append(menuItemFactory.create("Поздороваться", []() {
    std::cout << "General Kenobi: Hello there! <<"
    << "\n" <<
    "General Grivous: General Kenobi!" << std::endl;
  }));

  menu.append(menuItemFactory.create("Вывести логотип завода", []() {
    std::cout <<
    "██╗  ██╗██████╗  ██████╗ ███╗   ██╗ ██████╗ ███████╗" << "\n"
    "██║  ██║██╔══██╗██╔═══██╗████╗  ██║██╔═══██╗╚══███╔╝" << "\n" <<
    "███████║██████╔╝██║   ██║██╔██╗ ██║██║   ██║  ███╔╝ " << "\n" <<
    "██╔══██║██╔══██╗██║   ██║██║╚██╗██║██║   ██║ ███╔╝  " << "\n" <<
    "██║  ██║██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝███████╗" << "\n" <<
    "╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝" << std::endl;
  }));

  menu.append(menuItemFactory.create("Войти на завод", []() {
  }));

  menu.awaitUserInput();
}

void StartView::update() {
    std::cout << "Hello" << std::endl;
}
