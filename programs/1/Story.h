#pragma once
#include "Paragraph.h"

class Story {
    public:
        Story();
        Story operator+(const Story&);
        Story operator+(const int&);
        Story& operator++();
        Story& operator--();
        Story operator++(int);
        Story operator--(int);
        friend std::ostream& operator<<(std::ostream&, const Story&);
        Story* next;
        Paragraph first();
        Paragraph rest();
    private:
        Paragraph* head;
        Paragraph* tail;
};
