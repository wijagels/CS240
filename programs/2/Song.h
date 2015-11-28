#pragma once
#include "Time.h"

class Song {
    public:
        Song();
        Song(std::string, std::string, Time);
        std::string title;
        std::string artist;
        Time runtime;
};
