#include "AUser.h"

class Provider : public AUser<Provider> {
    void registrate() override;
};
