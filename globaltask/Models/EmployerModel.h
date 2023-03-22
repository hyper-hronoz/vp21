#include "AUser.h"
#include "IBinaryModel.h"

class EmployerModel : public AUser<EmployerModel>, public IBinaryModel<EmployerModel> {
 public:
    void signUp() override;

    void writeBinary() override {

    };
    void readBinary(EmployerModel& model) override {

    };
};
