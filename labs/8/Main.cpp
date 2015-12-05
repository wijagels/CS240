#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <sstream>
#include <fstream>

class City {
    public:
        City();
        explicit City(std::string);
        bool color = false;
        std::string name = "";
        std::list<City*> edges;
};
void file(char*);
void interactive();
template <class Instream>
void commands(Instream&);
bool home(City&);
bool path(City&, City&);
bool auxPath(City&, City&, std::queue<City>);
bool operator==(const City&, const City&);
std::vector<City> v;

int main(int argc, char** argv) {
    if(argc == 2)
        file(argv[1]);
    else
        interactive();
}

void file(char* f) {
    std::fstream fs;
    fs.open(f, std::fstream::in);
    commands(fs);
    fs.close();
}

void interactive() {
    commands(std::cin);
}

/*
 * Waow, templated function, much cool, less reuse
 */
template <class Instream>
void commands(Instream& in) {
    std::string t;// Smaller variable names = less bytes :)
    in >> t;
    int c = stoi(t);
    v.reserve(c+1);
    for(;c > 0;c--) {
        in >> t;
        v.push_back(City(t));
    }
    in >> t;
    c = stoi(t);
    for(;c > 0;c--) {
        in >> t;
        auto it = std::find(v.begin(), v.end(), City(t));
        in >> t;
        auto itt = std::find(v.begin(), v.end(), City(t));
        if(it == v.end() || itt == v.end()) {
            std::cout << "Invalid" << std::endl;
            return;
        }
        it->edges.push_back(&(*itt));
    }
    while(std::getline(in, t)) {
        std::istringstream ss(t);
        std::string s;
        ss >> s;
        if(s == "HOME") {
            ss >> s;
            std::cout << s << std::endl;
            auto it = std::find(v.begin(), v.end(), City(s));
            home(*it);
        }
        else if(s == "TRAVEL") {
            std::string c1, c2;
            ss >> c1;
            ss >> c2;
            auto it = std::find(v.begin(), v.end(), City(c1));
            auto itt = std::find(v.begin(), v.end(), City(c2));
            if(!path(*it, *itt))
                std::cout << "No path" << std::endl;
        }
    }
}

bool home(City& h) {
    for(auto i : h.edges) {
        if(path(*i, h)) return true;
    }
    return false;
}

bool path(City& from, City& to) {
    if(from == to) {
        return true;
    }
    from.color = true;
    std::queue<City> q;
    q.push(from);
    for(auto it : from.edges)
        if(auxPath(*it, to, q)) return true;
    return false;
}

bool auxPath(City& from, City& to, std::queue<City> q) {
    if(from.color)
        return false;
    q.push(from);
    from.color = true;
    if(from == to) {
        while(!q.empty()) {
            std::cout << q.front().name << " ";
            q.pop();
        }
        std::cout << std::endl;
        return true;
    }
    for(auto it : from.edges) {
        if(auxPath(*it, to, q))
            return true;
    }
    return false;
}

bool operator==(const City& lhs, const City& rhs) {
    return lhs.name == rhs.name;
}

City::City() {
}

City::City(std::string name) {
    this->name = name;
}
