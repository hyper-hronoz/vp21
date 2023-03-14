#include "MenuItem.h"

MenuItem::MenuItem(int id, std::string title) {
    this->title = title;
    this->id = id;
}

MenuItem::MenuItem(int id, std::string title, std::function<void()> callback) : MenuItem(id, title) {
    this->callback = callback;
    this->id = id;
}

std::string MenuItem::getTitle() {
    return this->title;
}

int MenuItem::getId() {
    return this->id;
}

void MenuItem::executeCallback() {
    callback();
}

MenuItem::~MenuItem() {}
