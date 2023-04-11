cmake_minimum_required(VERSION 3.0)

project(gg)

add_executable(gg
	./index.cpp                      
	./src/Controllers/StartController.cpp
	./src/Controllers/FirstLabController.cpp
	./src/Controllers/SecondLabController.cpp
	./src/Views/StartView.cpp            
	./src/Views/FirstLabView.cpp            
	./src/Views/SecondLabView.cpp            
	./src/Views/Menu/Menu.cpp            
	./src/Views/Menu/MenuItem.cpp        
	./src/Views/Menu/MenuItemFactory.cpp 
)
