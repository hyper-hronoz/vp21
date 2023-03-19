#include "StartView.h"

#include "../Controllers/StartController.h"

StartView::StartView(IController* controller) : AView(controller) {
    this->createStartMenu();
}

void StartView::display() {
    this->createStartMenu()->awaitUserInput();
}

Menu* StartView::createStartMenu() {
    Menu * menu = new Menu("---Стартовое меню[Вы кто?]---");

    menu->append(menuItemFactory->create("Поставщик", [this]() {
        dynamic_cast<StartController*>(this->controller)->onSelectProvider();
    }));

    menu->append(menuItemFactory->create("Сотрудник", [this]() {
        dynamic_cast<StartController*>(this->controller)->onSelectEmployer();
    }));

    return menu;
}
