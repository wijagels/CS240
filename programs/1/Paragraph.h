#ifndef PARAGRAPH_INCLUDE
#define PARAGRAPH_INCLUDE
#include "Sentence.h"
#include "Story.h"
class Story;
class Sentence;

class Paragraph {
    public:
        Paragraph();
        ~Paragraph();
        Paragraph(const Sentence&);
        Paragraph(const Paragraph&);
        void append(const Sentence&);
        void prepend(const Sentence&);
        Story operator+(const Story&);
        Paragraph operator+(const Paragraph&);
        Paragraph operator+(const Sentence&);
        Paragraph operator+(const int&);
        Paragraph& operator++();
        Paragraph& operator--();
        Paragraph operator++(int);
        Paragraph operator--(int);
        Paragraph* next = nullptr;
        friend std::ostream& operator<<(std::ostream&, const Paragraph&);
        Sentence first();
        Paragraph rest();
    private:
        Sentence* head = nullptr;
        Sentence* tail = nullptr;
};
#endif
