#include "AUser.h"

class ProviderModel : public AUser<ProviderModel> {
 public:
     void signUp() override;
};
