#pragma once

#include "../Views/StartView.h"

class StartController {
  explicit StartController(StartView view) {
    view.display();
  }
};

