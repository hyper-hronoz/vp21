#include "ProviderView.h"
#include "../Controllers/AuthenticationController.h"
#include "../Controllers/StartController.h"

void ProviderView::display() {
    this->menu->awaitUserInput();
}

void ProviderView::createProviderMenu() {
    this->menu = new Menu("---Меню поставщика---");

    menu->append(menuItemFactory->create("Войти как поставщик", [this]() {
        this->controller->run();
        // dynamic_cast<AuthenticationController*>(this->controller);
    }));

    menu->append(menuItemFactory->create("Вернуться в клавное меню", [this]() {
        // dynamic_cast<StartController*>(this->controller)->run();
    }));
}
