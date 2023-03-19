#include "SessionFactory.h"

Session* create(UserAccess userAccess) {
    return new Session(userAccess);
}
