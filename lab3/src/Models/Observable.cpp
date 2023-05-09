#include "Observable.h"

void Observervable::addObserver(Observer* observer) {
    this->observers.push_back(observer);
}

void Observervable::notifyChanges() {
  for (auto &observer : this->observers) {
    observer->update();
  }
}
