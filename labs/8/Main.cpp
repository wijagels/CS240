#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <sstream>

class City {
    public:
        City();
        City(std::string, std::string);
        explicit City(std::string);
        bool color = false;
        std::string name = "";
        std::list<City> edges;
};
void file(char*);
void interactive();
bool path(City&, City&);
bool auxPath(City&, City&, std::queue<City>);
bool operator==(const City&, const City&);
std::vector<City> v;

int main(int argc, char** argv) {
    if(argc == 2)
        file(argv[2]);
    else
        interactive();
}

void file(char* f) {
}

void interactive() {
    std::string t;// Smaller variable names = less bytes :)
    std::cin >> t;
    int c = stoi(t);
    for(;c > 0;c--) {
        std::cin >> t;
        v.push_back(City(t));
    }
    std::cin >> t;
    c = stoi(t);
    for(;c > 0;c--) {
        std::cin >> t;
        auto it = std::find(v.begin(), v.end(), City(t));
        std::cin >> t;
        auto itt = std::find(v.begin(), v.end(), City(t));
        if(it == v.end() || itt == v.end()) {
            std::cout << "Invalid" << std::endl;
            return;
        }
        it->edges.push_back(*itt);
    }
    while(std::getline(std::cin, t)) {
        std::istringstream ss(t);
        std::string s;
        ss >> s;
        if(s == "HOME") {
            ss >> s;
            std::cout << s << std::endl;
        }
        else if(s == "TRAVEL") {
            std::string c1, c2;
            ss >> c1;
            ss >> c2;
            auto it = std::find(v.begin(), v.end(), City(c1));
            auto itt = std::find(v.begin(), v.end(), City(c2));
            path(*it, *itt);
        }
    }
}

bool path(City& from, City& to) {
    if(from == to) {
        return true;
    }
    from.color = true;
    std::queue<City> q;
    q.push(from);
    for(auto it : from.edges) {
        std::cout << "Pathing: " << it.name << std::endl;
        auto itt = std::find(v.begin(), v.end(), it);
        if(auxPath(*itt, to, q)) return true;
    }
    return false;
}

bool auxPath(City& from, City& to, std::queue<City> q) {
    q.push(from);
    if(from == to) {
        while(!q.empty()) {
            std::cout << q.front().name << " ";
            q.pop();
        }
        std::cout << std::endl;
        return true;
    }
    for(auto it : from.edges) {
        std::cout << "Pathing: " << it.name << std::endl;
        auto itt = std::find(v.begin(), v.end(), it);
        if(auxPath(*itt, to, q)) {
            return true;
        }
    }
    return false;
}

bool operator==(const City& lhs, const City& rhs) {
    return lhs.name == rhs.name;
}

City::City() {
}

City::City(std::string name, std::string other) {
    this->name = name;
    this->edges.push_back(City(other));
}

City::City(std::string name) {
    this->name = name;
}
