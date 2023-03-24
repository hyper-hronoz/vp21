#pragma once

#include "Model.h"

template<class T>
class BinaryModel : public Model<T> {
 public:
    virtual void writeBinary() = 0;
    virtual void readBinary(T& t) = 0;
};
