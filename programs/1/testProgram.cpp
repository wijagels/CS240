#include <iostream>
using namespace std;

#include "Word.h"
#include "Sentence.h"
#include "Paragraph.h"
#include "Story.h"

int main ( ) {
   // None of the following does anything useful!
   // Just checking that functions get called as expected.
   // Word w1, w2, w3, w4, w5(w4), w6=w5;
   // Sentence s1, s2, s3, s4, s5(s4), s6=s5;
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
   // s1 = w1 + w2 + w3;
   // s2 = w2 + w4;
   // p1 = (s1 + s2);
   // st1 = st1 + p2 + ((p1 + p1 + p1) + 1);
   Word w1 = Word("lorem");
   Word w2 = Word("ipsum");
   Word w3 = Word("dolor");
   Sentence s1 = (w1 + w2);
   Paragraph p1 = (w1 + w2) + w3;
   Paragraph p2 = (w3 + w2) + w1;
   Story st1 = Story(p1);
   cout << "===Concatenation operators===" << endl << endl;

   cout << w1 + w2 << endl; // Word + Word
   cout << w1 + (w1 + w2) << endl; // Word + Sentence
   cout << (w1 + w2) + w3 << endl; // Sentence + Word
   cout << (w1 + w2) + (w2 + w3) << endl; // Sentence + Sentence
   cout << (w1 + w2) + ((w2 + w3) + (w2 + w3)) << endl; // Sentence + Paragraph
   cout << ((w1 + w2) + (w2 + w3)) + (w2 + w2) << endl; // Paragraph + Sentence
   cout << ((w1 + w2) + (w2 + w3)) + ((w1 + w2) + (w2 + w3)) << endl; // Paragraph + Paragraph
   cout << p2 + st1 << endl; // Paragraph + Story
   cout << st1 + p2 << endl; // Story + Paragraph
   cout << st1 + st1 << endl; // Story + Story

   cout << "===Prepend/Append operators===" << endl << endl;

   cout << w1++ << endl; // All caps
   cout << w1-- << endl; // All lowercase
   cout << s1++ << endl; // All caps Sentence
   cout << s1-- << endl; // All lowercase Sentence
   cout << p1++ << endl; // All caps Paragraph
   cout << p1-- << endl; // All lowercase Paragraph
   cout << st1++ << endl; // All caps Story
   cout << st1-- << endl; // All lowercase Story

   cout << ++w2 << endl; // Pig Latin
   cout << --w2 << endl; // Un Pig Latin
   cout << ++s1 << endl; // Pig Latin Sentence
   cout << --s1 << endl; // Un Pig Latin Sentence
   cout << ++p1 << endl; // Pig Latin Paragraph
   cout << --p1 << endl; // Un Pig Latin Paragraph
   cout << ++st1 << endl; // Pig Latin Story
   cout << --st1 << endl; // Un Pig Latin Story

   cout << "===Addition (int) operators===" << endl << endl;

   cout << w1 + 1 << endl; // Title case
   cout << s1 + 1 << endl; // Title case Sentence
   cout << p1 + 1 << endl; // Title case Paragraph
   cout << (st1 + p2) + 1 << endl; // Title case Story

   cout << "===First/Rest functions===" << endl << endl;
   cout << s1.first() << endl;
   cout << s1.rest() << endl;
   cout << p1.first() << endl;
   cout << p1.rest() << endl;
   cout << (st1 + p2).first() << endl;
   cout << (st1 + p2).rest() << endl;
}

