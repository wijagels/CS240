#ifndef WORD_INCLUDE
#define WORD_INCLUDE

#include <stdio.h>
#include <iostream>

class Word;
class Sentence;

#include "Sentence.h"
class Word {
    public:
        Word();
        ~Word();
        Word(const char*);
        Word(const Word&);
        Sentence operator+(const Word&);
        Word operator+(const int&);
        Word& operator++();
        Word& operator--();
        Word operator++(int);
        Word operator--(int);
        Word* next = nullptr;//Important for reasons
        friend std::ostream& operator<<(std::ostream&, const Word&);
        char* str;
};
#endif
