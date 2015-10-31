#ifndef WORD_INCLUDE
#define WORD_INCLUDE

#include <stdio.h>
#include <iostream>
#include <unordered_map>

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
        Sentence operator+(const Sentence&);
        Word operator+(const int&);
        Word& operator++();
        Word& operator--();
        Word operator++(int);
        Word operator--(int);
        Word* next = nullptr;
        friend std::ostream& operator<<(std::ostream&, const Word&);
        char* str;
        bool isPl = false;
        char* pl = nullptr;
};
#endif
