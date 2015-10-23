#include "Sentence.h"

Sentence::Sentence() {
    this->head = nullptr;
    this->tail = nullptr;
    this->next = nullptr;
    this->terminator = '.';
}

Sentence::~Sentence() {
    Word* w = this->head;
    Word *b;
    while(w) {
        b = w->next;
        delete(w);
        w = b;
    }
}

Sentence::Sentence(const Word& head) {
    this->head = new Word(head);
    const Word* w = &head;
    Word* insert = this->head;
    w = w->next;
    while(w) {
        insert->next = new Word(*w);
        insert = insert->next;
        w = w->next;
    }
    this->tail = insert;
}

Sentence::Sentence(const Sentence& s) {
    Word* w = s.head;
    this->head = new Word(*w);
    Word* cur = this->head;
    w = w->next;
    while(w) {
        cur->next = new Word(*w);
        cur = cur->next;
        w = w->next;
    }
    this->tail = cur;
}

std::ostream& operator<<(std::ostream& stream, const Sentence& s) {
    Word* w = s.head;
    while(w) {
        stream << *w;
        w = w->next;
        if(w) stream << " ";
    }
    stream << s.terminator;
    std::cout << "term here: " << s.terminator << std::endl;
    return stream;
}

void Sentence::append(const Word& other) {
    if(!this->head) {
        this->head = new Word(other);
        this->tail = this->head;
    }
    else {
        this->tail->next = new Word(other);
        this->tail = this->tail->next;
    }
}

void Sentence::setTerm(const char& c) {
    this->terminator = char(c);
}

Sentence Sentence::operator+(const Sentence& other) {
    Sentence sen = Sentence(*this);
    sen.tail->next = new Word(*other.head);
    sen.tail = new Word(*other.tail);
    return sen;
}
