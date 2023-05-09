#include "../Menu/MenuItemFactory.h"

MenuItem* MenuItemFactory::create(std::string title, std::function<void()> callback) {
    id++;
    MenuItem *menuItem = new MenuItem{id, title, callback};
    return menuItem;
}
