#include "cmath"
#include "FirstLabController.h"
#include "../Views/FirstLabView.h"

FirstLabController::FirstLabController() {
    this->view = new FirstLabView(this);
}

void FirstLabController::run() {
    this->view->display();
}

void FirstLabController::printHello() {
    std::cout << "Вжжжжжжжжжжжж, Hello there! General Kenobi!" << std::endl;
}

void FirstLabController::printLogo() {
    std::cout <<
    "██╗  ██╗██████╗  ██████╗ ███╗   ██╗ ██████╗ ███████╗" << "\n"
    "██║  ██║██╔══██╗██╔═══██╗████╗  ██║██╔═══██╗╚══███╔╝" << "\n" <<
    "███████║██████╔╝██║   ██║██╔██╗ ██║██║   ██║  ███╔╝ " << "\n" <<
    "██╔══██║██╔══██╗██║   ██║██║╚██╗██║██║   ██║ ███╔╝  " << "\n" <<
    "██║  ██║██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝███████╗" << "\n" <<
    "╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝" << std::endl;
}

void FirstLabController::printSqureRoot() {
    std::cout << sqrt(25) << std::endl;
}
