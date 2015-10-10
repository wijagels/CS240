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
        Word* next;
        friend std::ostream& operator<<(std::ostream&, const Word&);
   private:
        char str[];
};
