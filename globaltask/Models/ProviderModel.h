#include "AUser.h"
#include "IBinaryModel.h"

class ProviderModel : public AUser<ProviderModel>, public IBinaryModel<ProviderModel> {
 public:
    void signUp() override;

    void writeBinary() override {

    };
    void readBinary(ProviderModel& model) override {

    };
};
