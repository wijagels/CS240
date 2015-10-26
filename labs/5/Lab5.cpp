#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>

#include "Sorter.h"

#define DEFAULT_NUMVALUES 10
#define MAX_NUMVALUES 1000
#define MIN_NUMVALUES 1

int main (int argc, char **argv) {
   unsigned int numValues = DEFAULT_NUMVALUES; 
   int value;

   if (argc > 1)
      numValues = atoi(argv[1]);  
   if ((numValues < MIN_NUMVALUES) || (numValues > MAX_NUMVALUES)) {
      cerr << "Specify numValues in the range [" << MIN_NUMVALUES; 
      cerr << ", " << MAX_NUMVALUES << endl; 
      cerr << "\nUsage: " << argv[0] << " {numValues}" << endl; 
   }
   if (argc > 2) 
      cerr << "Ignoring extra command line arguments." << endl; 

   cout << endl << "Generating " << numValues << " values for sorting." << endl; 
   Sorter s;
   s.makeSpace(numValues); 

   srand(time(NULL)); // use this line for pseudo-random numbers 
   // srand(23);      // use this line for deterministic "random" numbers
  
   for (unsigned int i=0; i < numValues; i++) {
      value = rand() % 100;  
      s.insert(value); 
   } 

   cout << "Initial array: ";
   s.show(25, 10); 

   s.insertionSortI();
   cout << "After iterative Insertion Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.selectionSortI();
   cout << "After iterative Selection Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.bubbleSortI();
   cout << "After iterative Bubble Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.insertionSortR();
   cout << "After recursive Insertion Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.selectionSortR();
   cout << "After recursive Selection Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.bubbleSortR();
   cout << "After recursive Bubble Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 
}

