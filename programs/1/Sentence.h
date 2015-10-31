class Word;
class Sentence;

#ifndef SENTENCE_INCLUDE
#define SENTENCE_INCLUDE
#include "Word.h"
#include "Paragraph.h"

class Word;
class Paragraph;

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
        void prepend(const Word&);
        Paragraph operator+(const Sentence&);
        Paragraph operator+(const Paragraph&);
        Sentence operator+(const int&);
        Sentence& operator++();
        Sentence& operator--();
        Sentence operator++(int);
        Sentence operator--(int);
        Sentence* next = nullptr;
        friend std::ostream& operator<<(std::ostream&, const Sentence&);
        Word first();
        Sentence rest();
        void setTerm(const char&);
        Word* head = nullptr;
        Word* tail = nullptr;
    private:
        char terminator = '.';
};
#endif
