#pragma once
#include <string>
#include <sstream>
#include <iostream>

class Time {
    public:
        Time();
        explicit Time(int);
        Time(std::string);
        Time(std::string, bool);
        int increment(int);
        int increment(Time);
        std::string human() const;
        operator int() const;

    private:
        int sec = 0;
        bool music = false;
};
