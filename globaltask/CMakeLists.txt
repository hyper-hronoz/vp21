cmake_minimum_required(VERSION 3.0)

project(gg)

add_executable(gg
	./index.cpp                      
	./src/Controllers/StartController.cpp
	./src/Controllers/AuthenticationController.cpp
	./src/Controllers/IntroController.cpp
	./src/Controllers/ProviderController.cpp
	./src/Controllers/DirectorController.cpp
	./src/Controllers/EmployerController.cpp
	./src/Views/StartView.cpp            
	./src/Views/EmployerView.cpp           
	./src/Views/AuthEmployerSignUpView.cpp            
	./src/Views/AuthEmployerLoginView.cpp            
	./src/Views/AuthProviderSignUpView.cpp            
	./src/Views/AuthProviderLoginView.cpp            
	./src/Views/AuthDirectorLoginView.cpp
	./src/Views/AuthDirectorSignUpView.cpp
	./src/Views/DirectorView.cpp         
	./src/Views/IntoView.cpp            
	./src/Views/AuthenticationView.cpp
	./src/Views/ProviderView.cpp
	./src/Views/Menu/Menu.cpp            
	./src/Views/Menu/MenuItem.cpp        
	./src/Views/Menu/MenuItemFactory.cpp 
)
