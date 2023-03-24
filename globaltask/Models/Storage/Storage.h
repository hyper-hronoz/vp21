#pragma once

#include "iostream"
#include "ASaveStorageCallback.h"

class Storage {
 private:
    Storage() {}
    Storage(const Storage&);
    Storage& operator=(Storage&);

 public:
    static Storage& getInstance() {
        static Storage instance;
        return instance;
    }

    template<class T> void save(T* t, ASaveStorageCallback<T>* callback);
    template<class T> T* get(T t);
};
