#include <stdio.h>
#include <iostream>
class Word;
class Sentence;

#ifndef WORD_INCLUDE
#define WORD_INCLUDE
#include "Sentence.h"
class Word {
    public:
        Word();
        ~Word();
        Word(const char*);
        Sentence operator+(const Word&);
        Word operator+(const int&);
        Word& operator++();
        Word& operator--();
        Word operator++(int);
        Word operator--(int);
        Word* next;
        friend std::ostream& operator<<(std::ostream&, const Word&);
        char* str;
};
#endif
