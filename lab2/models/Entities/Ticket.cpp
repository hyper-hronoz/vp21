#include "../Entities/Ticket.h"

Ticket::Ticket(Session* session, Place* place) {
    this->session = session;
    this->place = place;
}

Place* Ticket::getPlace() {
    return this->place;
}

Session* Ticket::getSession() {
    return this->session;
}

void Ticket::print() {
    this->session->print();
    this->place->print();
}
