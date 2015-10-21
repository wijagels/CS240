#include "Word.h"
#include "Aux.h"

int main() {
    Word* w = new Word("hello");
    Word ww = Word("world");
    std::cout << *w << ww << std::endl;
    std::cout << strlen(w->str) << std::endl;
    char* s = copystr(w->str);
    delete(w);
    std::cout << s << std::endl;
    delete[] s;

    Word k = Word("hola");
    Word* kk = new Word("mundo");
    k.next = kk;
    Sentence sen = Sentence(k);
    std::cout << sen << std::endl;
}
