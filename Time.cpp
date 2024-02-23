#include "Time.h"

Time::Time() {
    hour = 0;
    minute = 0;
}

Time::Time(int _hour, int _minute) : hour(_hour), minute(_minute) {
    // if time is inputted incorrectly
    if (_hour < 0 || hour >= 24) {
        hour = 0;
    }

    if (_minute < 0 || _minute >= 60) {
        minute = 0;
    }
}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

void Time::setHour(int _hour) {
    hour = _hour;
}

void Time::setMinute(int _min) {
    minute = _min;
}

void Time::display() const {
    if (hour < 10 && minute < 10) {
        cout << "0" << hour << ":0" << minute;
    } else if (hour < 10 && (minute >= 10)) {
        cout << "0" << hour << ":" << minute;
    } else if (hour >= 10 && minute < 10) {
        cout << hour << ":0" << minute;
    } else if (hour > 10 && minute >= 10) {
        cout << hour << ":" << minute;
    }
}