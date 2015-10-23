#include "Aux.h"

int strlen(const char* s) {
    int c = 0;
    while(*s != '\0') {
        c++;
        s++;
    }
    return c;
}

char* copystr(const char* s) {
    char* n = new char[strlen(s)];
    for(int i=0;i<strlen(s);i++) {
        n[i] = s[i];
    }
    n[strlen(s)] = '\0';
    return n;
}
