#include "../Utils/Place.h"

Place::Place(int row, int column) {
    this->row = row;
    this->column = column;
}

int Place::getRow() {
    return this->row;
}

int Place::getColumn() {
    return this->column;
}

void Place::print() {
    std::cout << "Ряд: " << this->row << ", "
        << "Место: " << this->column << std::endl;
}

