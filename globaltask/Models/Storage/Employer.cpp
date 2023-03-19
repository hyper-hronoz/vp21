#include "Employer.h"

void Employer::registrate() {
    Employer *employer = new Employer();

    Employer *sameEmployer = this->findOne(employer);

    if (sameEmployer) {
        std::cout << "Поставщик с этим email уже существует" << std::endl;
        return;
    }

    sameEmployer->save();
}

