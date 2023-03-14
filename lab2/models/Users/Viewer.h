#pragma once
#include "../Users/AUser.h"

class Viewer : public AUser {
 private:
    Ticket* ticket;
 public:
    explicit Viewer(Ticket* ticket);

    Ticket* ticketTransaction() override;
};

