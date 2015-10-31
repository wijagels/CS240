#include "Story.h"

Story::Story() {
}

Story::Story(const Paragraph& p) {
    this->head = new Paragraph(p);
    const Paragraph* w = &p;
    Paragraph* insert = this->head;
    w = w->next;
    while(w) {
        insert->next = new Paragraph(*w);
        insert = insert->next;
        w = w->next;
    }
    this->tail = insert;
}

Story::Story(const Story& other) {
    Paragraph* p = other.head;
    while(p) {
        this->append(*p);
        p = p->next;
    }
}

Story::~Story() {
    Paragraph* s = this->head;
    Paragraph* b;
    while(s) {
        b = s->next;
        delete(s);
        s = b;
    }
}

void Story::save(char* str) {
    std::ofstream file;
    file.open(str);
    file << *this << std::endl;
    file.close();
}

Story::Story(char* str) {
    std::string line;
    std::ifstream file;
    file.open(str);
    if(file.is_open()) {
        while(std::getline(file, line)) {
            if(line == "") {
                continue;
            }
            std::stringstream ss(line);
            std::string word;
            Word* head;
            Word* cur;
            Sentence sentence = Sentence();
            Paragraph par = Paragraph();
            while(std::getline(ss, word, ' ')) {
                int loc = word.find('.');
                if(loc==-1) loc = word.find('?');
                if(loc==-1) loc = word.find('!');
                if(loc != -1) {
                    sentence.setTerm(word.at(loc));
                    word.erase(loc);
                    Word* w = new Word(word.c_str());
                    sentence.append(*w);
                    delete(w);
                    par.append(sentence);
                    sentence = Sentence();
                }
                else {
                    Word* w = new Word(word.c_str());
                    sentence.append(*w);
                    delete(w);
                }
            }
            this->append(par);
        }
    }
    else
        std::cout << "File failed to open" << std::endl;
}

void Story::append(const Paragraph& other) {
    if(!this->head) {
        this->head = new Paragraph(other);
        this->tail = this->head;
    }
    else {
        this->tail->next = new Paragraph(other);
        this->tail = this->tail->next;
    }
}

void Story::prepend(const Paragraph& other) {
    if(!this->head) {
        this->append(other);
        return;
    }
    Paragraph *h = this->head;
    this->head = new Paragraph(other);
    this->head->next = h;
}

Paragraph Story::first() {
    return Paragraph(*this->head);
}

Story Story::rest() {
    if(this->head->next)
        return Story(*this->head->next);
    return Story();
}

Story Story::operator+(const Story& other) {
    Story ret = Story(*this);
    Paragraph* h = other.head;
    while(h) {
        ret.append(*h);
        h = h->next;
    }
    return ret;
}

Story Story::operator+(const Paragraph& other) {
    Story ret = Story(*this);
    ret.append(other);
    return ret;
}

Story Story::operator+(const int& i) {
    if(i != 1) return *this;
    Paragraph* paragraph = this->head;
    while(paragraph) {
        paragraph->operator+(1);
        paragraph = paragraph->next;
    }
    return *this;
}

Story Story::operator++(int) {
    Paragraph* paragraph = this->head;
    while(paragraph) {
        paragraph->operator++(1738);
        paragraph = paragraph->next;
    }
    return *this;
}

Story Story::operator--(int) {
    Paragraph* paragraph = this->head;
    while(paragraph) {
        paragraph->operator--(1738);
        paragraph = paragraph->next;
    }
    return *this;
}

Story& Story::operator++() {
    Paragraph* paragraph = this->head;
    while(paragraph) {
        paragraph->operator++();
        paragraph = paragraph->next;
    }
    return *this;
}

Story& Story::operator--() {
    Paragraph* paragraph = this->head;
    while(paragraph) {
        paragraph->operator--();
        paragraph = paragraph->next;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Story& story) {
    Paragraph* p = story.head;
    while(p) {
        stream << *p;
        p = p->next;
        if(p) stream << "\n\n";
        else stream << "\n";
    }
    return stream;
}
