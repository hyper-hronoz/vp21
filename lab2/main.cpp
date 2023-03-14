#include<iostream>

#include "./models/Users/Viewer.h"
#include "./models/Users/Cashier.h"
#include "MenuItem.h"
#include "MenuItemFactory.h"
#include "Menu.h"
#include "math.h"

int main() {
    Menu *menu = new Menu("Menu title");

    MenuItemFactory *menuItemFactory = new MenuItemFactory{};

    Cashier *cashier = new Cashier();

    Ticket* ticket;

    Viewer *viewer;

     menu->append(menuItemFactory->create("Вычеслить корень 25", []() {
        std::cout << "Полезная логика!!!!!!!!" << std::endl;
        std::cout << sqrt(25) << std::endl;
    }));

    menu->append(menuItemFactory->create("Поздороваться", []() {
        std::cout << "Вжжжжжжжжжжжж, Hello there! General Kenobi!" << std::endl;
    }));

    menu->append(menuItemFactory->create("Изобразить картинку псевдографикой!", []() {
        std::cout <<
        "██╗  ██╗██████╗  ██████╗ ███╗   ██╗ ██████╗ ███████╗" << "\n"
        "██║  ██║██╔══██╗██╔═══██╗████╗  ██║██╔═══██╗╚══███╔╝" << "\n" <<
        "███████║██████╔╝██║   ██║██╔██╗ ██║██║   ██║  ███╔╝ " << "\n" <<
        "██╔══██║██╔══██╗██║   ██║██║╚██╗██║██║   ██║ ███╔╝  " << "\n" <<
        "██║  ██║██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝███████╗" << "\n" <<
        "╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝" << std::endl;
    }));

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
