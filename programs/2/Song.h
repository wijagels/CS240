#pragma once
#include "Time.h"

class Song {
    public:
        Song();
        Song(std::string, std::string, Time);
        void updoot();
        void downdoot();
        int score(Time) const;
        std::string title;
        std::string artist;
        Time runtime;
        Time last;
        int updoots = 0;
    private:
        friend bool operator>(const Song&, const Song&);
        friend bool operator<(const Song&, const Song&);
        friend std::ostream & operator<< (std::ostream &os, const Song&);
};
