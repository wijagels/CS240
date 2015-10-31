#include "Word.h"
#include "Aux.h"

std::unordered_map<char, char> vowels = {{'a',1},{'e',1},{'i',1},{'o',1},{'u',1},{'y',1}};

Word::Word() {
    this->str = nullptr;
    this->next = nullptr;
}

Word::Word(const char* string) {
    this->str = copystr(string);
    this->next = nullptr;
}

Word::Word(const Word& other) {
    this->str = copystr(other.str);
    this->next = nullptr;
}

Word::~Word() {
    delete[] str;
    if(pl)
    delete[] pl;
}

Sentence Word::operator+(const Word& other) {
    Word w = Word(other);
    Sentence ret = Sentence(*this);
    ret.append(w);
    return ret;
}

Sentence Word::operator+(const Sentence& other) {
    Sentence ret = Sentence(other);
    ret.prepend(*this);
    return ret;
}

Word Word::operator+(const int& i) {
    if(i != 1) return *this;
    int k = 0;
    if(this->str[i] == '\t') ++k;
    if(this->str[k] > 96 && this->str[k] < 123) {
        str[k] -= 32;
    }
    return *this;
}

Word Word::operator++(int n) {
    for(int i=0;i<strlen(this->str);i++) {
        if(this->str[i] > 96 && this->str[i] < 123) {
            str[i] -= 32;
        }
    }
    return *this;
}

Word Word::operator--(int n) {
    for(int i=0;i<strlen(this->str);i++) {
        if(this->str[i] > 64 && this->str[i] < 91) {
            str[i] += 32;
        }
    }
    return *this;
}

Word& Word::operator++() {
    // Starts with vowel
    if(vowels.find(this->str[0]) != vowels.end()) {
        char* old = this->str;
        this->pl = addW(this->str);
        char* oldd = this->pl;
        this->pl = addAy(this->pl);
        delete[] oldd;
    }
    else {
        int len = strlen(this->str);
        int i;
        for(i=0;vowels.find(this->str[i]) == vowels.end();i++) {}
        this->pl = new char[len+1];
        for(int j = i;j < len;j++) {
            this->pl[j-i] = this->str[j];
        }
        for(int k = 0;k < i + len;k++) {
            this->pl[len - (i-k)] = this->str[k];
        }
        this->pl[len] = '\0';
        char* old = this->pl;
        this->pl = addAy(this->pl);
        delete[] old;
    }
    this->isPl = true;
    return *this;
}

Word& Word::operator--() {
    this->isPl = false;
    return *this;
}

std::ostream& operator<<(std::ostream& st, const Word& w) {
    if(w.isPl)
        st << w.pl;
    else
        st << w.str;
    return st;
}
