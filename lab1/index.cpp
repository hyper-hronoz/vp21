#include<iostream>
#include<vector>
#include<functional>
#include <math.h>
#include "Menu.h"
#include "MenuItem.h"
#include "MenuItemFactory.h"

using namespace std;

int main() {
    Menu *menu = new Menu("Menu title");

    MenuItemFactory *menuItemFactory = new MenuItemFactory{};

    menu->append(menuItemFactory->create("Вычеслить корень 25", []() {
        cout << "Полезная логика!!!!!!!!" << endl;
        cout << sqrt(25) << endl;
    }));

    menu->append(menuItemFactory->create("Поздороваться", []() {
        cout << "Вжжжжжжжжжжжж, Hello there! General Kenobi!" << endl;
    }));

    menu->append(menuItemFactory->create("Изобразить картинку псевдографикой!", []() {
        cout <<
        "██╗  ██╗██████╗  ██████╗ ███╗   ██╗ ██████╗ ███████╗" << "\n"
        "██║  ██║██╔══██╗██╔═══██╗████╗  ██║██╔═══██╗╚══███╔╝" << "\n" <<
        "███████║██████╔╝██║   ██║██╔██╗ ██║██║   ██║  ███╔╝ " << "\n" <<
        "██╔══██║██╔══██╗██║   ██║██║╚██╗██║██║   ██║ ███╔╝  " << "\n" <<
        "██║  ██║██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝███████╗" << "\n" <<
        "╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝" << endl;
    }));

    menu->awaitUserInput();

    delete menuItemFactory;

    return 0;
}
