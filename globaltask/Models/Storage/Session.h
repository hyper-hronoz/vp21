#pragma once
#include "UserAccess.h"

class Session {
 private:
     UserAccess userAccess;

 public:
    explicit Session(UserAccess userAccess);
};

