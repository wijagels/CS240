#include "Word.h"

Word::Word(const char* string) {
    const char* stringcopy = string;
    int count = 0;
    while(*stringcopy != '\0') {
        count++;
        stringcopy++;
    }
    str = new char[count+1];
    for(int i=0;i<count+1;i++) {
        str[i] = string[i];
    }
}

Word Word::operator+(const Word& other) {
    char ns[strlen(this->str) + strlen(other.str)];
    return Word(ns);
}

std::ostream& operator<<(std::ostream& st, const Word& w) {
    st << w.str;
    return st;
}

int strlen(const char string[]) {
    return 1;
}
