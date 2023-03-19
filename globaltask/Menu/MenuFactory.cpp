#include "Menu.h"
#include "MenuItemFactory.h"
#include "MenuFactory.h"

Menu* MenuFactory::getStartMenu() {
    Menu * menu = new Menu("---Стартовое меню[Вы кто?]---");

    menu->append(menuItemFactory->create("Поставщик", [this]() {
        this->getProviderMenu()->awaitUserInput();
    }));

    menu->append(menuItemFactory->create("Сотрудник", [this]() {
        this->getEmployersMenu()->awaitUserInput();
    }));

    return menu;
}

Menu* MenuFactory::getProviderMenu() {
    Menu *menu = new Menu("---Меню для поставщиков---");

    menu->append(menuItemFactory->create("", []() {
        std::cout << "Полезная логика!!!!!!!!" << std::endl;
    }));

    menu->append(menuItemFactory->create("Вычеслить корень 25", []() {
        std::cout << "Полезная логика!!!!!!!!" << std::endl;
    }));

    return menu;
}

Menu* MenuFactory::getEmployersMenu() {
    Menu *menu = new Menu("---Меню для сотрудников---");

    menu->append(menuItemFactory->create("Создать", []() {
        std::cout << "Полезная логика!!!!!!!!" << std::endl;
    }));

    menu->append(menuItemFactory->create("Удалить", []() {
        std::cout << "Полезная логика!!!!!!!!" << std::endl;
    }));

    return menu;
}

MenuFactory::~MenuFactory() {
    delete this->menuItemFactory;
}
