#include "HashHeap.h"
#include "Radio.h"

#include <iostream>
#include <sstream>
#include <fstream>

int main() {
    bool mkay = true;
    while(mkay) {
        Radio r = Radio();
        std::string s;
        std::getline(std::cin, s);
        std::istringstream ss(s);
        mkay = r.logic(&ss);
    }
    // HashHeap<int> hh(100);
    // for(int i=0;i < 20;i++) {
    //     hh.insert(i);
    // }
    // std::cout << hh << std::endl;
}
