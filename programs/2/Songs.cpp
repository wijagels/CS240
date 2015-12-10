#include "Songs.h"

Songs::Songs() {
}

Songs::Songs(Time t, int m) : time(t), max(m), hh(m) {}

void Songs::push(Song s) {
    hh.insert(s);
}
