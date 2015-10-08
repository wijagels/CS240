#pragma once
#include "Sentence.h"

class Paragraph {
    public:
        Paragraph();
        Paragraph operator+(const Paragraph&);
        Paragraph operator+(const int&);
        Paragraph& operator++();
        Paragraph& operator--();
        Paragraph operator++(int);
        Paragraph operator--(int);
        std::ostream& operator<<(const Paragraph&);
        Paragraph* next;
        Sentence first();
        Sentence rest();
    private:
        Sentence* head;
        Sentence* tail;
};
