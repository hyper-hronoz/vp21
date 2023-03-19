#include "StartView.h"

StartView::StartView() {
    this->createStartMenu();
}

void StartView::display() {
    this->createStartMenu()->awaitUserInput();
}

Menu* StartView::createStartMenu() {
    Menu * menu = new Menu("---Стартовое меню[Вы кто?]---");

    menu->append(menuItemFactory->create("Поставщик", [this]() {

    }));

    menu->append(menuItemFactory->create("Сотрудник", [this]() {
    }));

    return menu;
}
