#include "Songs.h"

Songs::Songs() {
    this->time = Time();
    this->max = 0;
}

Songs::Songs(Time t, int m) {
    this->time = t;
    this->max = m;
    this->sarr = new Song[m];
}

// Warning, this is a bad placeholder.
// Will cause buffer overrun if too many songs inserted.
void Songs::push(Song s) {
    sarr[++size] = s;
}
