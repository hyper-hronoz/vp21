#pragma once
#include "iostream"

class Place {
 private:
    int row;
    int column;

 public:
    Place(int row, int column);

    int getRow();

    int getColumn();

    void print();
};

