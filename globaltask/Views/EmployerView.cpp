#include "EmployerView.h"
#include "../Controllers/AuthenticationController.h"

void EmployerView::display() {
    this->menu->awaitUserInput();
}

void EmployerView::createEmployerMenu() {
    this->menu = new Menu("---Меню сотрудника---");

    menu->append(menuItemFactory->create("Войти как сотрудник", [this]() {
        // dynamic_cast<AuthenticationController*>(this->controller);
    }));

    menu->append(menuItemFactory->create("Вернуться в клавное меню", [this]() {
        // dynamic_cast<StartController*>(this->controller)->run();
    }));
}
