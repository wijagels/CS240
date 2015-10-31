#include "Aux.h"

int strlen(const char* s) {
    if(!s) return 0;
    int c = 0;
    while(*s != '\0') {
        c++;
        s++;
    }
    return c;
}

char* copystr(const char* s) {
    char* n = new char[strlen(s)+1];
    for(int i=0;i<strlen(s);i++) {
        n[i] = s[i];
    }
    n[strlen(s)] = '\0';
    return n;
}

char* addAy(const char* s) {
    char* n = new char[strlen(s)+3];
    for(int i=0;i<strlen(s);i++) {
        n[i] = s[i];
    }
    n[strlen(s)] = 'a';
    n[strlen(s)+1] = 'y';
    n[strlen(s)+2] = '\0';
    return n;
}

char* addW(const char* s) {
    char* n = new char[strlen(s)+2];
    for(int i=0;i<strlen(s);i++) {
        n[i] = s[i];
    }
    n[strlen(s)] = 'w';
    n[strlen(s)+1] = '\0';
    return n;
}
