#include <sstream>
#include <iostream>
#include <fstream>

#include "Time.h"
#include "Song.h"
#include "Songs.h"

class Radio {
    public:
        Radio();
        bool logic(std::istringstream*);
    private:
        Songs song_list;
};
