#include "Model.h"
#include "fstream"

template<class T>
T* Model<T>::findOne(T *t) {
    return {};
}

template<class T>
std::vector<T*> Model<T>::getAll() {
}

template<class T>
void Model<T>::save() {
    std::ofstream file(this->type, std::ios::out | std::ios::binary);
    if (!file) {
        return;
    }
    file.close();
}

template<class T>
T Model<T>::getType() {
    return this->type;
}

