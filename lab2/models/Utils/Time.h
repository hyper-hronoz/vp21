#pragma once
#include "iostream"

class Time {
 private:
    int hours;
    int minutes;

 public:
    explicit Time();

    Time(int hours, int minutes);

    int getHours();
    int getMinutes();
    void print();
};

