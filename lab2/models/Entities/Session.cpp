#include "../Entities/Session.h"


Session::Session(Time startTime, Time endTime, std::string name) {
    this->startTime = startTime;
    this->endTime = endTime;
    this->name = name;
}

Time Session::getStartTime() {
    return this->startTime;
}

Time Session::getEndTime() {
    return this->endTime;
}

std::string Session::getName() {
    return this->name;
}

int Session::getHole() {
    return this->hole;
}

void Session::print() {
    std::cout << "Название: " << this->name << std::endl;
    std::cout << "Время начала: "; this->startTime.print();
    std::cout << "Время конца: "; this->endTime.print();
    std::cout << "Номер зала: " << this->hole << std::endl;
}
