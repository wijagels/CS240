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
        Paragraph* next;
        friend std::ostream& operator<<(std::ostream&, const Paragraph&);
        Sentence first();
        Sentence rest();
    private:
        Sentence* head;
        Sentence* tail;
};
