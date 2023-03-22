#pragma once

#include "vector"
#include "Storage.h"
#include <typeinfo>

template<class T>
class Model {
    Storage *storage;

 public:
    Model() {

    };

    virtual T* findOne(T *t) {
        return {};
    }

    virtual std::vector<T*> getAll() {
        return {};
    }

    virtual void save() {
    }

    T getType();
};

