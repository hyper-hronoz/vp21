#pragma once

#include "cmath"
#include "BaseView.h"

class IntroView : public BaseView {
public:
  IntroView() { this->menu = Menu("---First lab view---"); }

  void printGraphics() {
        std::cout <<
        "██╗  ██╗██████╗  ██████╗ ███╗   ██╗ ██████╗ ███████╗" << "\n"
        "██║  ██║██╔══██╗██╔═══██╗████╗  ██║██╔═══██╗╚══███╔╝" << "\n" <<
        "███████║██████╔╝██║   ██║██╔██╗ ██║██║   ██║  ███╔╝ " << "\n" <<
        "██╔══██║██╔══██╗██║   ██║██║╚██╗██║██║   ██║ ███╔╝  " << "\n" <<
        "██║  ██║██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝███████╗" << "\n" <<
        "╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝" << std::endl;
  }

  void sayHello() {
    std::cout << "Вжжжжжжжжжжжж, Hello there! General Kenobi!" << std::endl;
  }

  void calculateSqureRoot() {
    std::cout << sqrt(25) << std::endl;
  }

  void display() override;
};
