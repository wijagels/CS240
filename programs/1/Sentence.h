#pragma once
#include "Word.h"

class Sentence {
    public:
        Sentence();
        Sentence operator+(const Sentence&);
        Sentence operator+(const int&);
        Sentence& operator++();
        Sentence& operator--();
        Sentence operator++(int);
        Sentence operator--(int);
        std::ostream& operator<<(const Sentence&);
        Word* next;
        Word first();
        Word rest();
    private:
        Word* head;
        Word* tail;
};
