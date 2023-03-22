#include "ProviderModel.h"
#include "./Storage/Storage.cpp"

void ProviderModel::signUp() {
    Storage::getInstance().save(this);
}
