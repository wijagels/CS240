class Word;
class Sentence;

#ifndef SENTENCE_INCLUDE
#define SENTENCE_INCLUDE
#include "Word.h"
class Sentence {
    public:
        Sentence();
        ~Sentence();
        Sentence(const Sentence&);
        Sentence(const Word&);
        Sentence operator+(const Sentence&);
        Sentence operator+(const int&);
        Sentence& operator++();
        Sentence& operator--();
        Sentence operator++(int);
        Sentence operator--(int);
        Sentence* next;
        friend std::ostream& operator<<(std::ostream&, const Sentence&);
        Word first();
        Word rest();
    private:
        Word* head;
        Word* tail;
};
#endif
