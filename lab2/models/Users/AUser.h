#pragma once
#include "string"
#include "../Entities/Ticket.h"


class AUser {
 protected:
    std::string name;
    std::string sername;

    int age;

    std::string login;
    std::string password;

 public:
    virtual Ticket* ticketTransaction() = 0;
};
