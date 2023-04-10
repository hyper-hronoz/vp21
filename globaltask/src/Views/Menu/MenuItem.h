#pragma once
#include "iostream"
#include "functional"

class MenuItem {
 private:
    std::string title;
    int id;
    std::function<void()> callback;

 public:
    MenuItem(int id, std::string title);

    MenuItem(int id, std::string title, std::function<void()> callback);

    std::string getTitle();

    int getId();

    void executeCallback();

    ~MenuItem();
};
