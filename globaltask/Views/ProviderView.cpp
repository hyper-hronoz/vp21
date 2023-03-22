#include "ProviderView.h"

#include "../Controllers/AuthenticationController.h"
#include "../Controllers/StartController.h"

void ProviderView::display() {
    this->createProviderMenu();
    this->menu->awaitUserInput();
}

void ProviderView::createProviderMenu() {
    this->menu->setTitle("--Меню поставщика--");

    menu->append(menuItemFactory->create("Войти как поставщик", [this]() {
    }));

    menu->append(menuItemFactory->create("Вернуться в клавное меню", [this]() {
        this->controller->getInstance<ProviderController>()->goMain();
    }));
}
