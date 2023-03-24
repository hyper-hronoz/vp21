#pragma once

#include "fstream"

template<class T>
class ASaveStorageCallback {
 private:
     T* model;
     std::ofstream stream;

 public:
     ASaveStorageCallback(T* t, std::ofstream stream) {
         this.model = t;
         this->stream = stream;
     }

     T* getModel() {
         return this->model;
     }

     std::ofstream getStrem() {
         return this->stream;
     }

     virtual void exec() = 0;
};
