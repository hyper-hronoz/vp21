#pragma once

#include "fstream"

template<class MODEL>
class StorageCallback {
 private:
     MODEL* model;
     std::fstream* stream;

 public:
     StorageCallback(MODEL* model, std::fstream* stream) {
         this->model = model;
         this->stream = stream;
     }

     MODEL* getModel() {
         return this->model;
     }

     std::fstream* getStream() {
         return this->stream;
     }

     virtual void exec() = 0;
};
