#include "Provider.h"

void Provider::registrate() {
    Provider *provider = new Provider();

    Provider *sameProvider = this->findOne(provider);

    if (sameProvider) {
        std::cout << "Поставщик с этим email уже существует" << std::endl;
        return;
    }

    provider->save();
}

