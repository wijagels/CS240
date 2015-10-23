#include "Word.h"
#include "Sentence.h"
#include "Paragraph.h"
#include "Story.h"
#include "Aux.h"

int main() {
    Word* k = new Word("hola");
    Word* kk = new Word("mundo");
    k->next = kk;
    Word w = Word("the");
    Word ww = Word("quick");
    Word www = Word("fox");
    w.next = &ww;
    ww.next = &www;
    Sentence sen = Sentence(*k);
    Sentence ss = Sentence(w);
    sen.next = new Sentence(ss);
    // std::cout << sen << std::endl;
    // std::cout << ss << std::endl;
    Paragraph p = Paragraph(sen);
    // std::cout << p << std::endl;
    Story st = Story(p);
    //st.save("out.txt");
    Story read = Story("./STORIES/FreshPrince.txt");
    read.save("fp.txt");
}
