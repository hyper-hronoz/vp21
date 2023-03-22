#include "EmployerView.h"
#include "../Controllers/AuthenticationController.h"

void EmployerView::display() {
    this->createEmployerMenu();
    this->menu->awaitUserInput();
}

void EmployerView::createEmployerMenu() {
    this->menu->setTitle("--Меню сотрудника--");

    menu->append(menuItemFactory->create("Войти как сотрудник", [this]() {
    }));

    menu->append(menuItemFactory->create("Вернуться в клавное меню", [this]() {
    }));
}
