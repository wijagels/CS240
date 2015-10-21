#include "Sentence.h"

Sentence::Sentence() {
    this->head = nullptr;
    this->tail = nullptr;
    this->next = nullptr;
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
    while(w != nullptr) {
        insert->next = new Word(*w);
        insert = insert->next;
        w = w->next;
    }
    this->tail = insert;
}

Sentence::Sentence(const Sentence& s) {
    Word* w = s.head;
    this->head = new Word(*w);
}

std::ostream& operator<<(std::ostream& stream, const Sentence& s) {
    Word* w = s.head;
    while(w) {
        stream << *w;
        w = w->next;
        if(w) stream << " ";
    }
    return stream;
}

Sentence Sentence::operator+(const Sentence& other) {
    Sentence sen = Sentence(*this);
    sen.tail->next = new Word(*other.head);
    sen.tail = new Word(*other.tail);
    return sen;
}
