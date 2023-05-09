#pragma once
#include "MyMenuItems.h"

using namespace MM;

class MyMenu
{
private:
    std::string header;
    MyMenuItems* items;
    int numberOfItems;
    void writeMenu();
    void outOfSystem(int choice);
public:
    bool wrong;
    std::string getHeader();
    void setHeader(std::string);
    void setitems(MyMenuItems* items);
    MyMenu();
    MyMenu(int numberOfItems, std::string header, MyMenuItems* items);
    int starting();
};

