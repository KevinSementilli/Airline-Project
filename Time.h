#pragma once
#ifndef ASSIGNMENT2_TIME_H
#define ASSIGNMENT2_TIME_H

#include <iostream>
using namespace std;


class Time {
public:
    Time();
    Time(int hour, int minute);

    //getters
    [[nodiscard]] int getHour() const;
    [[nodiscard]] int getMinute() const;

     //setters
    void setHour(int);
    void setMinute(int);

    void display() const;

private:
    int hour;
    int minute;
};

#endif //ASSIGNMENT2_TIME_H