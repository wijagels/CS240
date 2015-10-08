#pragma once
#include <stdio.h>
#include <iostream>

class Word {
    public:
        Word();
        Word operator+(const Word&);
        Word operator+(const int&);
        Word& operator++();
        Word& operator--();
        Word operator++(int);
        Word operator--(int);
        std::ostream& operator<<(const Word&);
        Word* next;
   private:
        char str[];
};
