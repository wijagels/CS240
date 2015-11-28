#include "Time.h"

Time::Time() {
    this->sec = 0;
}

Time::Time(long int s) {
    this->sec = s;
}

Time::Time(std::string s) {
    this->sec = 0;
    int p = 0;
    int i = s.find(":");
    for(int k = 0;k < 3;k++) {
        // Warning, ninja coding ahead.
        this->sec += std::stoi(s.substr(p, 2)) *(k==0 ? 3600 : k==1 ? 60 : 1);
        p = i+1;
        i = s.find(":", i+1);
    }
}

long int Time::increment(long int t) {
    this->sec += t;
    return this->sec;
}

long int Time::increment(Time t) {
    this->sec += t.sec;
    return this->sec;
}

std::string Time::human() {
    std::stringstream ss;
    ss << "Day ";
    ss << (sec / (24 * 60 * 60))+1;
    ss << ": ";
    ss << (sec / (60 * 60)) % 24 << ":";
    char buf[3];
    std::sprintf(buf, "%02ld", (sec / 60) % 60);
    ss << buf << ":";
    std::sprintf(buf, "%02ld", sec % 60);
    ss << buf;
    return ss.str();
}
