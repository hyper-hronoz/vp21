#pragma once

#include "iostream"
#include "AView.h"

class StartView : public AView {
 public:
  StartView();

  void update() override;
};
