#include <iostream>
#include "MyMenu.h"
#include "MyMenuItems.h"


int func1() {
    std::cout << "1.";
    return 1;
}
int func2() {
    std::cout << "2.";
    return 2;
}
int func3() {
    std::cout << "3.";
    return 3;
}
int main()
{
    MyMenuItems point1("Calculate root of 25", func1);
    MyMenuItems point2("Greet the user", func2);
    MyMenuItems point3("Draw a picture", func3);

    MyMenuItems menuArray[3] = { point1, point2, point3 };

    MyMenu myMenu(3, "Console Menu", menuArray);

    do {
        myMenu.starting();
    } while (myMenu.wrong);
    return 0;
}


