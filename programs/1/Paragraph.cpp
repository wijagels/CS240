#include "Paragraph.h"

Paragraph::Paragraph() {
    this->head = nullptr;
    this->tail = nullptr;
    this->next = nullptr;
}

Paragraph::Paragraph(const Sentence& s) {
    this->head = new Sentence(s);
    Sentence* cur = this->head;
    const Sentence* sen = &s;
    sen = sen->next;
    while(sen) {
        cur->next = new Sentence(*sen);
        cur = cur->next;
        sen = sen->next;
    }
    this->tail = cur;
}

Paragraph::Paragraph(const Paragraph& p) {
    Sentence* s = p.head;
    this->head = new Sentence(*s);
    Sentence* cur = this->head;
    s = s->next;
    while(s) {
        cur->next = new Sentence(*s);
        cur = cur->next;
        s = s->next;
    }
    this->tail = cur;
}

Paragraph::~Paragraph() {
    Sentence* s = this->head;
    Sentence* b;
    while(s) {
        b = s->next;
        delete(s);
        s = b;
    }
}

void Paragraph::append(const Sentence& other) {
    if(!this->head) {
        this->head = new Sentence(other);
        this->tail = this->head;
    }
    else {
        this->tail->next = new Sentence(other);
        this->tail = this->tail->next;
    }
}

std::ostream& operator<<(std::ostream& stream, const Paragraph& p) {
    //stream << '\t';
    Sentence* s = p.head;
    while(s) {
        stream << *s;
        s = s->next;
        /*if(s)*/ stream << " ";
        /* ^ Trailing spaces, EW GROSS! :( */
    }
    return stream;
}
