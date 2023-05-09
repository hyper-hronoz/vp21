#include <iostream>
#include "MyMenu.h"
#include "MyMenuItems.h"


std::string MyMenu::getHeader() {
    return header;
}

void MyMenu::setHeader(std::string header) {
    this->header = header;
}

void MyMenu::setitems(MyMenuItems* items) {
    this->items = items;
}
MyMenu::MyMenu(int numberOfItems, std::string header, MyMenuItems* items) {
    this->numberOfItems = numberOfItems;
    this->header = header;
    this->items = items;
}
MyMenu::MyMenu() {}

void MyMenu::writeMenu() {
    std::cout << "\n" << header;
    for (int i = 0; i < numberOfItems; i++)
    {
        std::cout << "\n" << i + 1 << ")" << items[i].getHeader();
    }
    std::cout << "\n" << "0)" << "kfrf=";
}
int MyMenu::starting() {
    writeMenu();
    std::cout << "\n" << "\n" << "frvfb: ";
    int choice;
    std::cin >> choice;
    outOfSystem(choice);
    std::cout << "\n";
    return items[choice - 1].getFunc();
}
void MyMenu::outOfSystem(int choice) {
    if (choice == 0) {
        wrong = false;
        std::cout << "\n" << "verfev...";
    }
    else {
        wrong = true;
    }
}



