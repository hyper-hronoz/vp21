#include "ProviderView.h"

#include "../Controllers/StartController.h"
#include "../Controllers/ProviderController.h"

void ProviderView::display() {
    this->createProviderMenu();
    this->menu->awaitUserInput();
}

void ProviderView::createProviderMenu() {
    this->menu->setTitle("--Меню поставщика--");
    // menu->append(menuItemFactory->create("Войти как поставщик", [this]() {
    //     this->controller->getInstance<ProviderController>()->goSignUp();
    // }));

    menu->append(menuItemFactory->create("Зарегистрировать как поставщик", [this]() {
        this->controller->getInstance<ProviderController>()->goSignUp();
    }));

    menu->append(menuItemFactory->create("Вернуться в клавное меню", [this]() {
        this->controller->getInstance<ProviderController>()->goMain();
    }));
}
