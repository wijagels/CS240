#pragma once
#include <stdio.h>
#include <iostream>

class Word {
    public:
        Word();
        Word(const char*);
        Word operator+(const Word&);
        Word operator+(const int&);
        Word& operator++();
        Word& operator--();
        Word operator++(int);
        Word operator--(int);
        Word* next;
        friend std::ostream& operator<<(std::ostream&, const Word&);
        char* str;
};

int strlen(const char string[]);
