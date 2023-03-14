#pragma once
#include "../Users/AUser.h"

class Cashier : public AUser {
 public:
    Ticket* ticketTransaction() override;
};
