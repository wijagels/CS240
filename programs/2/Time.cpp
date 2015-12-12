#include "Time.h"

Time::Time() {
    this->sec = 0;
}

Time::Time(int s) {
    this->sec = s;
}

Time::Time(std::string s) {
    this->sec = 0;
    int p = 0;
    int i = s.find(":");
    for(int k = 0;k < 3;k++) {
        // Warning, ninja coding ahead.
        this->sec += std::stoi(s.substr(p, 2)) * (k==0 ? 3600 : k==1 ? 60 : 1);
        p = i+1;
        i = s.find(":", i+1);
    }
}

Time::Time(std::string s, bool b) {
    music = b;
    this->sec = 0;
    int p = 0;
    int i = s.find(":");
    for(int k = 0;k < 2;k++) {
        // Warning, ninja coding ahead.
        this->sec += std::stoi(s.substr(p, 2)) * (k==0 ? 60 : 1);
        p = i+1;
        i = s.find(":", i+1);
    }
}

int Time::increment(int t) {
    this->sec += t;
    return this->sec;
}

int Time::increment(Time t) {
    this->sec += t.sec;
    return this->sec;
}

std::string Time::human() const {
    std::stringstream ss;
    if(music) {
        char buf[3];
        std::sprintf(buf, "%02d", (sec / 60) % 60);
        ss << buf << ":";
        std::sprintf(buf, "%02d", sec % 60);
        ss << buf;
        return ss.str();
    }
    ss << "Day ";
    ss << (sec / (24 * 60 * 60))+1;
    ss << ": ";
    ss << (sec / (60 * 60)) % 24 << ":";
    char buf[3];
    std::sprintf(buf, "%02d", (sec / 60) % 60);
    ss << buf << ":";
    std::sprintf(buf, "%02d", sec % 60);
    ss << buf;
    return ss.str();
}

Time::operator int() const {
    return this->sec;
}
