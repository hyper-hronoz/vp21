#pragma once

// template<class MODEL = int, class VIEW = int>
template<class VIEW = int, class MODEL = int>
class IController {
 protected:
  MODEL model;
  VIEW view;
 public:
  IController(MODEL model, VIEW view) : model(model), view(view) {}
  IController(){}
};


