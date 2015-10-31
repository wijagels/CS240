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
    if(p.head) {
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

void Paragraph::prepend(const Sentence& other) {
    if(!this->head) {
        this->append(other);
        return;
    }
    Sentence* h = this->head;
    this->head = new Sentence(other);
    this->head->next = h;
}


Sentence Paragraph::first() {
    return Sentence(*this->head);
}

Paragraph Paragraph::rest() {
    if(this->head->next)
        return Paragraph(*this->head->next);
    return Paragraph();
}

Story Paragraph::operator+(const Story& other) {
    Story ret = Story(other);
    ret.prepend(*this);
    return ret;
}

Paragraph Paragraph::operator+(const Paragraph& other) {
    Paragraph ret = Paragraph(*this);
    Sentence* h = other.head;
    while(h) {
        ret.append(*h);
        h = h->next;
    }
    return ret;
}

Paragraph Paragraph::operator+(const Sentence& other) {
    Paragraph ret = Paragraph(*this);
    ret.append(other);
    return ret;
}

Paragraph Paragraph::operator+(const int& i) {
    if(i != 1) return *this;
    Sentence* sentence = this->head;
    while(sentence) {
        sentence->operator+(1);
        sentence = sentence->next;
    }
    return *this;
}

Paragraph& Paragraph::operator++() {
    Sentence* sentence = this->head;
    while(sentence) {
        sentence->operator++();
        sentence = sentence->next;
    }
    return *this;
}

Paragraph& Paragraph::operator--() {
    Sentence* sentence = this->head;
    while(sentence) {
        sentence->operator--();
        sentence = sentence->next;
    }
    return *this;
}

Paragraph Paragraph::operator++(int) {
    Sentence* sentence = this->head;
    while(sentence) {
        sentence->operator++(1738);
        sentence = sentence->next;
    }
    return *this;
}

Paragraph Paragraph::operator--(int) {
    Sentence* sentence = this->head;
    while(sentence) {
        sentence->operator--(1738);
        sentence = sentence->next;
    }
    return *this;
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
