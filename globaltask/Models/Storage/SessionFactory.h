#pragma once
#include "Session.h"

class SessionFactory {
 public:
    Session* create(UserAccess userAccess);
};
