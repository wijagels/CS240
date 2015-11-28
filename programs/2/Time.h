#pragma once
#include <string>
#include <sstream>
#include <iostream>

class Time {
    public:
        Time();
        Time(long int);
        Time(std::string);
        long int increment(long int);
        long int increment(Time);
        std::string human();

        long int sec = 0;
};
