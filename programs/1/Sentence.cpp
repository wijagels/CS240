#include "Sentence.h"

Sentence::Sentence() {
    this->head = nullptr;
    this->tail = nullptr;
    this->next = nullptr;
    //this->terminator = '.';
}

Sentence::~Sentence() {
    Word* w = this->head;
    Word* b;
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
    if(s.head) {
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
        this->terminator = s.terminator;
    }
}

Word Sentence::first() {
    return Word(*this->head);
}

Sentence Sentence::rest() {
    if(this->head->next)
        return Sentence(*this->head->next);
    return Sentence();
}

std::ostream& operator<<(std::ostream& stream, const Sentence& s) {
    Word* w = s.head;
    while(w) {
        stream << *w;
        w = w->next;
        if(w) stream << " ";
    }
    if(s.terminator) stream << s.terminator;
    return stream;
}

void Sentence::append(const Word& other) {
    if(!this->head) {
        Word* w = new Word(other);
        this->head = w;
        this->tail = this->head;
    }
    else {
        this->tail->next = new Word(other);
        this->tail = this->tail->next;
    }
}

void Sentence::prepend(const Word& other) {
    if(!this->head) {
        this->append(other);
        return;
    }
    Word* h = this->head;
    this->head = new Word(other);
    this->head->next = h;
}

void Sentence::setTerm(const char& c) {
    this->terminator = char(c);
}

Paragraph Sentence::operator+(const Sentence& other) {
    Paragraph p = Paragraph(*this);
    p.append(other);
    return p;
}

Paragraph Sentence::operator+(const Paragraph& other) {
    Paragraph p = Paragraph(other);
    p.prepend(*this);
    return p;
}

Sentence Sentence::operator+(const int& i) {
    if(i != 1) return *this;
    if(this->head)
        this->head->operator+(1);
    return *this;
}

Sentence& Sentence::operator++() {
    Word* word = this->head;
    while(word) {
        word->operator++();
        word = word->next;
    }
    return *this;
}

Sentence& Sentence::operator--() {
    Word* word = this->head;
    while(word) {
        word->operator--();
        word = word->next;
    }
    return *this;
}

Sentence Sentence::operator++(int) {
    Word* word = this->head;
    while(word) {
        word->operator++(1738);
        word = word->next;
    }
    return *this;
}

Sentence Sentence::operator--(int) {
    Word* word = this->head;
    while(word) {
        word->operator--(1738);
        word = word->next;
    }
    return *this;
}

