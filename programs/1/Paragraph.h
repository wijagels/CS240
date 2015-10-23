#ifndef PARAGRAPH_INCLUDE
#define PARAGRAPH_INCLUDE
#include "Sentence.h"

class Paragraph {
    public:
        Paragraph();
        ~Paragraph();
        Paragraph(const Sentence&);
        Paragraph(const Paragraph&);
        void append(const Sentence&);
        Paragraph operator+(const Paragraph&);
        Paragraph operator+(const int&);
        Paragraph& operator++();
        Paragraph& operator--();
        Paragraph operator++(int);
        Paragraph operator--(int);
        Paragraph* next = nullptr;
        friend std::ostream& operator<<(std::ostream&, const Paragraph&);
        Sentence first();
        Sentence rest();
    private:
        Sentence* head = nullptr;
        Sentence* tail = nullptr;
};
#endif
