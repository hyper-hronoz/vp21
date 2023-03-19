#include "iostream"
#include "Menu/MenuItemFactory.h"
#include "Menu/Menu.h"
#include "AView.h"

class StartView : public AView {
 private:
    MenuItemFactory* menuItemFactory = new MenuItemFactory();

 public:
    explicit StartView();

    ~StartView() {
        delete this->menuItemFactory;
    };
    
    void display() override;

 private:
    Menu* createStartMenu();
};
