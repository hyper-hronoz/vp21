#include "FirstLabView.h"
#include "../Controllers/FirstLabController.h"

void FirstLabView::display() {
    this->createFirstLabMenu();
    this->menu->awaitUserInput();
}

void FirstLabView::createFirstLabMenu() {
    this->menu->setTitle("---Меню первой лабы---");

    menu->append(menuItemFactory->create("Поздороваться", [this]() {
        this->controller->getInstance<FirstLabController>()->printHello();
    }));

    menu->append(menuItemFactory->create("Вывести корень 25", [this]() {
        this->controller->getInstance<FirstLabController>()->printSqureRoot();
    }));

    menu->append(menuItemFactory->create("Вывести псевдографику", [this]() {
        this->controller->getInstance<FirstLabController>()->printLogo();
    }));
}

