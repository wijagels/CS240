class Word;
class Sentence;

#ifndef SENTENCE_INCLUDE
#define SENTENCE_INCLUDE
#include "Word.h"
class Sentence {
    public:
        Sentence();
        ~Sentence();
        /**
         * Overrides the default copy constructor
         * in favor of a deep copy
         */
        Sentence(const Sentence&);
        Sentence(const Word&);
        void append(const Word&);
        Sentence operator+(const Sentence&);
        Sentence operator+(const int&);
        Sentence& operator++();
        Sentence& operator--();
        Sentence operator++(int);
        Sentence operator--(int);
        Sentence* next = nullptr;
        friend std::ostream& operator<<(std::ostream&, const Sentence&);
        Word first();
        Word rest();
        void setTerm(const char&);
        Word* head = nullptr;
        Word* tail = nullptr;
    private:
        char terminator;
};
#endif
