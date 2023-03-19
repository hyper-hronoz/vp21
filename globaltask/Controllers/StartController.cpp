#include "StartController.h"

void StartController::run() {
    this->startView->display();
}

void StartController::onSelectProvider() {
    std::cout << "Provider selected" << std::endl;
}

void StartController::onSelectEmployer() {
    std::cout << "Employer selected" << std::endl;
}

