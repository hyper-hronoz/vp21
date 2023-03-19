#include "AUser.h"

class Employer : public AUser<Employer> {
    void registrate() override;
};

