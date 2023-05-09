#include "Menu.h"
#include <limits>

Menu::Menu() {}

Menu::Menu(std::string name) {
  this->title = name;
  menuItems = {};
}

Menu::~Menu() {
  for (auto item : this->menuItems) {
    delete item;
  }
  menuItems.clear();
}

void Menu::append(MenuItem *menuItem) { menuItems.push_back(menuItem); }

void Menu::print() {
  std::cout << this->title << std::endl;
  for (auto menuItem : menuItems) {
    std::cout << menuItem->getId() << ") " << menuItem->getTitle() << std::endl;
  }
}

void Menu::setName(std::string name) { this->title = name; }

std::string Menu::getName() { return this->title; }

void Menu::awaitUserInput() {
  this->print();
  int input = 0;
  std::cout << "   >> Select: ";
  std::cin >> input;

  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ксива! Ввёв число жива!";
    std::cin >> input;
  }

  for (auto menuItem : this->menuItems) {
    if (menuItem->getId() == input) {
      system("clear");
      menuItem->executeCallback();
      awaitUserInput();
    }
  }

  std::cout << "!Incorrect selection!" << std::endl;
  awaitUserInput();
}
