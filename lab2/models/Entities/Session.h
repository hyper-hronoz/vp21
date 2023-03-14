#pragma once
#include "../Utils/Time.h"
#include "iostream"

class Session {
 private:
    Time startTime;
    Time endTime;

    std::string name;

    int hole;

 public:
    explicit Session();

    Session(Time startTime, Time endTime, std::string name);

    Time getStartTime();

    Time getEndTime();

    std::string getName();

    int getHole();

    void print();
};
