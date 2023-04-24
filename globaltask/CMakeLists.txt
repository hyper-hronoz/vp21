cmake_minimum_required(VERSION 3.0)

project(gg)

add_executable(gg
	./index.cpp                      
	./src/Controllers/StartController.cpp
	./src/Controllers/AuthenticationController.cpp
	./src/Controllers/IntroController.cpp
	./src/Controllers/ProviderController.cpp
	./src/Views/StartView.cpp            
	./src/Views/AuthEmployerSignUpView.cpp            
	./src/Views/AuthEmployerLoginView.cpp            
	./src/Views/AuthProviderSignUpView.cpp            
	./src/Views/AuthProviderLoginView.cpp            
	./src/Views/IntoView.cpp            
	./src/Views/AuthenticationView.cpp
	./src/Views/ProviderView.cpp
	./src/Views/Menu/Menu.cpp            
	./src/Views/Menu/MenuItem.cpp        
	./src/Views/Menu/MenuItemFactory.cpp 
)
