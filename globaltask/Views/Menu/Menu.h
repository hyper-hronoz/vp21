#pragma once
#include <string>
#include "iostream"
#include "vector"
#include "MenuItem.h"
#include "MenuItemFactory.h"

class Menu {
 private:
    std::string title;
    std::vector<MenuItem*> menuItems;

 public:
    explicit Menu();

    explicit Menu(std::string name);

    ~Menu() {
        // for (auto item : this->menuItems) {
        //    delete item;
        // }
        // menuItems.clear();
    }

    void append(MenuItem* menuItem);

    void print();

    void setName(std::string name);

    std::string getName();

    void awaitUserInput();
};

