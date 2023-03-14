#pragma once
#include "../Entities/Session.h"
#include "../Utils/Place.h"

class Ticket { private:
    Session *session;
    Place *place;

 public:
    Ticket(Session* session, Place* place);

    Place* getPlace();

    Session* getSession();

    void print();
};
