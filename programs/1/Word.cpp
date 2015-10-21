#include "Word.h"
#include "Aux.h"

Word::Word() : Word("hello"){
}

Word::Word(const char* string) {
    this->str = copystr(string);
    this->next = nullptr;
}

Word::~Word() {
    delete[] str;
}

Sentence Word::operator+(const Word& other) {
    Word* w = new Word(other);
    Word* ret = new Word(*this);
    ret->next = w;
    return Sentence(*ret);
}

std::ostream& operator<<(std::ostream& st, const Word& w) {
    st << w.str;
    return st;
}
