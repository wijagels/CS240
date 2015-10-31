#ifndef STORY_INCLUDE
#define STORY_INCLUDE
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Paragraph.h"
#include "Sentence.h"
#include "Word.h"
#include "Aux.h"
class Story;
class Paragraph;
class Sentence;
class Word;

class Story {
    public:
        Story();
        Story(const Story&);
        Story(const Paragraph&);
        Story(char*);
        ~Story();
        void save(char*);
        void append(const Paragraph&);
        void prepend(const Paragraph&);
        Story operator+(const Story&);
        Story operator+(const Paragraph&);
        Story operator+(const int&);
        Story& operator++();
        Story& operator--();
        Story operator++(int);
        Story operator--(int);
        friend std::ostream& operator<<(std::ostream&, const Story&);
        Story* next;
        Paragraph first();
        Story rest();
    private:
        Paragraph* head = nullptr;
        Paragraph* tail = nullptr;
};
#endif
