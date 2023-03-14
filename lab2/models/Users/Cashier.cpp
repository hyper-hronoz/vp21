#include "../Users/AUser.h"
#include "../Users/Cashier.h"

Ticket* Cashier::ticketTransaction() {
    std::cout << "Giving ticket to Viewer" << std::endl;

    Time startTime(12, 30);
    Time endTime(14, 30);

    return new Ticket(new Session(startTime, endTime,
                "Night time rable"), new Place(12, 20));
}
