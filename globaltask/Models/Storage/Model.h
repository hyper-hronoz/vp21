#pragma once

#include "vector"
#include "Storage.h"
#include <typeinfo>

template<class T>
class Model {
    // Storage *storage = new Storage();

    Model();

    virtual T* findOne(T *t);

    virtual std::vector<T*> getAll();

    virtual void save();

    T getType();
};

