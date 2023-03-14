#include<iostream>

#include "./models/Users/Viewer.h"
#include "./models/Users/Cashier.h"
#include "MenuItem.h"
#include "MenuItemFactory.h"
#include "Menu.h"

int main() {
    Menu *menu = new Menu("Menu title");

    MenuItemFactory *menuItemFactory = new MenuItemFactory{};


    Cashier *cashier = new Cashier();

    Ticket* ticket;

    Viewer *viewer;

    menu->append(menuItemFactory->create("╰─Провести транзакцию билета от касира к зрителю", [&ticket, &cashier, &viewer]() {
        ticket = cashier->ticketTransaction();
        viewer = new Viewer(ticket);
    }));

    menu->append(menuItemFactory->create("╰─Узнать о билете", [&ticket]() {
        if (ticket) {
            ticket->print();
        } else {
            std::cout << "Пошел вон заяц!" << std::endl;
        }
    }));

    menu->append(menuItemFactory->create("╰─Провести транзакцию билета от зрителя к кондуктору", [&viewer]() {
        Ticket* userTicket = viewer->ticketTransaction();
        if (userTicket) {
            std::cout << "Добро пожаловать в театр имени Баумана!" << std::endl;
            return;
        }
        delete userTicket;
    }));

    menu->awaitUserInput();

    delete menu;
    delete cashier;
    delete viewer; 
    delete ticket;

    return 0;
}
