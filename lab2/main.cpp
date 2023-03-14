#include<iostream>

#include "./models/Users/Viewer.h"
#include "./models/Users/Cashier.h"

int main() {
    Cashier *cashier = new Cashier();

    Ticket* ticket = cashier->ticketTransaction();

    ticket->print();

    Viewer *viewer = new Viewer(ticket);

    Ticket* userTicket = viewer->ticketTransaction();

    userTicket->print();

    return 0;
}
