#pragma once


template<class T>
class IBinaryModel {
    virtual void writeBinary() = 0;
    virtual void readBinary(T& t) = 0;
};
