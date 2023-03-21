#include "AUser.h"

class EmployerModel : public AUser<EmployerModel> {
 public:
     void signUp() override;
};
