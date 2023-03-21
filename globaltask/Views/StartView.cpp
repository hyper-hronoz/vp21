#include "StartView.h"

#include "../Controllers/StartController.h"

void StartView::display() {
    this->createStartMenu();
    this->menu->awaitUserInput();
}

void StartView::createStartMenu() {
    this->menu = new Menu("---Стартовое меню[Вы кто?]---");

    menu->append(menuItemFactory->create("Поставщик", [this]() {
        this->controller->getInstance<StartController>()->onSelectProvider();
    }));

    menu->append(menuItemFactory->create("Сотрудник", [this]() {
        this->controller->getInstance<StartController>()->onSelectEmployer();
    }));
}
