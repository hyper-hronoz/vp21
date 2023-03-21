#include "./Menu/Menu.h"
#include "AView.h"

class EmployerView : public AView<EmployerView> {
 public:
    explicit EmployerView(IController<EmployerView>* controller)
        : AView<EmployerView>(controller) {}

    void display() override;

 private:
    void createEmployerMenu();
};
