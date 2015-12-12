#include "Song.h"

Song::Song() {
}

Song::Song(std::string n) : title(n) {}

Song::Song(std::string n, std::string a, Time t) : title(n), artist(a), runtime(t) {}

void Song::updoot() {
    if(updoots < 0)
        updoots = 1;
    else
        ++updoots;
}

void Song::downdoot() {
    if(updoots > 0)
        updoots = -1;
    else
        --updoots;
}

int Song::score(Time now) const {
    return (now - last) + (1000 * updoots);
}

bool operator>(const Song& s1, const Song& s2) {
    Time offset;
    if(s1.last > s2.last)
        offset = s1.last;
    else
        offset = s2.last;
    return s1.score(offset) > s2.score(offset);
}

bool operator<(const Song& s1, const Song& s2) {
    Time offset;
    if(s1.last > s2.last)
        offset = s1.last;
    else
        offset = s2.last;
    return s1.score(offset) < s2.score(offset);
}

std::ostream & operator<< (std::ostream &os, const Song& song) {
    os << song.artist << " " << song.title << " " << song.runtime.human() << " " <<
        song.score(song.last);
    return os;
}


bool operator==(const Song& s1, const Song& s2) {
    return s1.title == s2.title;
}
