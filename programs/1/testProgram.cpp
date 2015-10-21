#include <iostream>
using namespace std;

#include "Word.h"
#include "Sentence.h"
#include "Paragraph.h"
#include "Story.h"

int main ( ) {
   // None of the following does anything useful!
   // Just checking that functions get called as expected.
   Word w1, w2, w3, w4, w5(w4), w6=w5;
   Sentence s1, s2, s3, s4, s5(s4), s6=s5;
   // Paragraph p1, p2, p3(p2), p4=p3;
   // Story st1, st2, st3(st2), st4=st3;
   // w1++;
   // w1--;
   // --w1;
   // ++w1;
   // s1++;
   // s1--;
   // ++s1;
   // --s1;
   s1 = w1 + w2 + w3;
   s2 = w2 + w4;
   //p1 = (s1 + s2);
   //st1 = st1 + p2 + ((p1 + p1 + p1) + 1);
}
