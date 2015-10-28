#include <iostream>
using namespace std;

#include "Sorter.h"

void Sorter::swap(int i, int j) {
   int tmp;
   tmp = array[i];
   array[i] = array[j];
   array[j] = tmp;
   return;
}

Sorter::Sorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;
}

Sorter::Sorter(unsigned int initialCapacity) {
   capacity = initialCapacity;
   numElements = 0;
   array = new int[capacity];
}

unsigned int Sorter::makeSpace(unsigned int newCapacity) {
   int *old;
   unsigned int i;
   if (newCapacity > capacity) {
      old = array;
      array = new int[newCapacity];
      for (i=0; i<numElements; i++)
         array[i] = old[i];
      capacity = newCapacity;
      delete old;
   }

   return capacity;
}

void Sorter::clear() {
   numElements = 0;
   return;
}

bool Sorter::insert(int element) {
   if (numElements >= capacity)
      return false;
   array[numElements++] = element;
   return true;
}

Sorter::~Sorter() {
   if (array) {
      delete[] array; // This line was wrong.
      numElements = 0;
   }
}

// Shuffle array elements
void Sorter::shuffle() {
   unsigned int j;
   for (unsigned int i=1; i<numElements; i++) {
      j = rand() % i;
      swap(i, j);
   }
}

// Show the first n elements, k per line, using <<
void Sorter::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity);
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " ";
   }
   cout << endl << endl;
}

// Iterative Insertion Sort
void Sorter::insertionSortI() {
    for(unsigned int i=1;i<this->numElements;i++) {
        int cur = array[i];
        int k = i-1;
        while(k >= 0 && array[k] > cur) {
            swap(k+1, k);
            --k;
        }
    }
}

// Iterative Selection Sort
void Sorter::selectionSortI() {
    for(unsigned int i=0;i<this->numElements-1;i++) {
        unsigned int minimum = i;
        unsigned int k;
        for(k=i+1;k<this->numElements;k++)
            if(array[k] < array[minimum])
                minimum = k;
        if(minimum != k)
            swap(minimum, i);
    }
}

// Iterative Bubble Sort
void Sorter::bubbleSortI() {
    for(unsigned int i=0;i<this->numElements-1;i++)
        for(unsigned int k=0;k<this->numElements-1;k++)
            if(array[k] > array[k+1])
                swap(k, k+1);
}

// Recursive Insertion Sort
void Sorter::insertionSortR() {
    insertionSortRAux(1);
}

void Sorter::insertionSortRAux(unsigned int l) {
    if(!(l < this->numElements)) return;
    int cur = array[l];
    insertionSortRAux2(l-1, cur);
    insertionSortRAux(++l);
}

void Sorter::insertionSortRAux2(int l, int cur) {
    if(l < 0) return;
    if(array[l] < cur) return;
    swap(l+1, l);
    insertionSortRAux2(--l, cur);
}

// Recursive Selection Sort
void Sorter::selectionSortR() {
    selectionSortRAux(0);
}

void Sorter::selectionSortRAux(unsigned int l) {
    if(!(l < this->numElements-1)) return;
    unsigned int min = l;
    selectionSortRAux2(l+1, min);
    if(min != l)
        swap(min, l);
    selectionSortRAux(++l);
}

void Sorter::selectionSortRAux2(unsigned int k, unsigned int& min) {
    if(k >= this->numElements) return;
    if(array[k] < array[min])
        min = k;
    selectionSortRAux2(++k, min);
}

// Recursive Bubble Sort
void Sorter::bubbleSortR() {
    bubbleSortRAux(0);
}

void Sorter::bubbleSortRAux(unsigned int l) {
    if(!(l < this->numElements)) return;// Base Case
    bubbleSortRAux2(0);
    bubbleSortRAux(++l);
}

void Sorter::bubbleSortRAux2(unsigned int l) {
    if(l == this->numElements-1) return;
    if(array[l] > array[l+1])
        swap(l, l+1);
    bubbleSortRAux2(++l);
}
