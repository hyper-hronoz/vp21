cmake_minimum_required(VERSION 3.0)

project(ebane)

add_executable(ebane
    ./src/Views/Menu/Menu.cpp
    ./src/Models/Observable.cpp
    ./src/Views/Menu/MenuItem.cpp
    ./src/Views/Menu/MenuItemFactory.cpp
    ./src/Views/StartView.cpp
    ./src/Controllers/StartController.cpp
    ./main.cpp
)

