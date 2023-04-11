#include "StartController.h"
#include "IntroController.h"
#include "AuthenticationController.h"

void StartController::onSelectFirstLab() {
   IntroController();
}

void StartController::onSelectSecondLab() {
  AuthenticationController();
}

void StartController::onSelectThirdLab() {

}

