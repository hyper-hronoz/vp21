#pragma once

#include "iostream"
#include "vector"
#include "../Views/Observer.h"

class Observervable {
 private:
  std::vector<Observer*> observers;
 public:
  void addObserver(Observer* observer);
  void notifyChanges();
};
