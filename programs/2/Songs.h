#include "Song.h"
#include "Time.h"
class Song;

class Songs {
    public:
        Songs();
        Songs(Time, int);
        void push(Song);

        Time time;
        int max = 0;
        int size = 0;
        Song* sarr;
};
