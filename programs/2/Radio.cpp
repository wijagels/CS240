#include "Radio.h"

Radio::Radio() {
}

bool Radio::logic(std::istringstream* s) {
    if(s->str() == "QUIT") {
        std::cout << "Bye" << std::endl;
        std::cout << this->song_list.hh;
        return false;
    }
    std::string f;
    *s >> f;
    if(f == "INIT") {
        *s >> f;
        Time time = Time(f);
        *s >> f;
        int max = stoi(f);
        song_list = Songs(time, max);
        return true;
    }
    if(f == "RUN") {
        std::string fname;
        *s >> fname;
        std::ifstream file(fname);
        if(!file.is_open()) {
            std::cout << "Error opening file" << std::endl;
            return false;
        }
        std::string l;
        while(getline(file, l)) {
            std::istringstream ss(l);
            if(!logic(&ss)) return false;
        }
        file.close();
        return true;
    }
    if(f == "ADD") {
        std::string tok;
        *s >> std::ws; // Trim whitespace
        std::getline(*s, tok, ',');
        *s >> std::ws;
        std::string title = tok;
        std::getline(*s, tok, ',');
        *s >> std::ws;
        std::string artist = tok;
        std::getline(*s, tok, ',');
        *s >> std::ws;
        Time rt(tok, true);
        song_list.push(Song(title, artist, rt));
        std::cout << "Added " << artist << " " << title << std::endl;
        return true;
    }
    if(f == "PLAY") {
        std::cout << "Thanks for the play command" << std::endl;
        return true;
    }
    if(f == "LIKE") {
        std::cout << "Thanks for the like command" << std::endl;
        return true;
    }
    if(f == "DISLIKE") {
        std::cout << "Thanks for the dislike command" << std::endl;
        return true;
    }
    return true;
}
