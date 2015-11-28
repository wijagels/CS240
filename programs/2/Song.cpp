#include "Song.h"

Song::Song() {
}

Song::Song(std::string n, std::string a, Time t) {
    this->title = n;
    this->artist = a;
    this->runtime = t;
}
