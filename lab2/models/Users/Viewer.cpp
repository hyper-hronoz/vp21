#include "../Users/Viewer.h"

Viewer::Viewer(Ticket *ticket) {
    this->ticket = ticket;
}

Ticket* Viewer::ticketTransaction() {
    std::cout << "Giving ticket to controller" << std::endl;
    if (this->ticket) {
        return this->ticket;
    }
    return {};
}
