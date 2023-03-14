#include "../Utils/Time.h"

Time::Time() {}

Time::Time(int hours, int minutes) {
    this->hours = hours;
    this->minutes = minutes;
}

int Time::getHours() {
    return this->hours;
}

int Time::getMinutes() {
    return this->minutes;
}

void Time::print() {
    std::cout << this->hours << ":" << this->minutes << std::endl;
}

