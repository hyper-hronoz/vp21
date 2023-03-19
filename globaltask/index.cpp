#include<iostream>
#include<fstream>

#include "./Menu/MenuFactory.h" 

using namespace std;

int main() {
    MenuFactory *menuFactory = new MenuFactory();

    Menu *menu = menuFactory->getStartMenu();
    menu->awaitUserInput();

    cout << menuFactory << endl;
    return 0;
}
