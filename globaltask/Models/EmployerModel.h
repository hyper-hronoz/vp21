#pragma once

#include "AUser.h"
#include "vector"

enum JOB_TITLE {
    JONIOR,
    MIDDLE,
    SENIOR,
    BLOW_UP_YOUR_BRAIN_WITH_DIRUGINA,
};

class EmployerModel : public AUser<EmployerModel> {
 protected:
     std::vector<JOB_TITLE> jobTitle;
};
