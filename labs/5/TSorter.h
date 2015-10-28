#ifndef TSORTER_INCLUDE
#define TSORTER_INCLUDE
#include <iostream>
using namespace std;
#include <vector>
#include <iterator>
#include <algorithm>

#include <cstdlib>


template <typename T> class TSorter {
    private:
        vector<T> array;
        unsigned int numElements;
        unsigned int capacity;
        typedef typename vector<T>::iterator tIter; // Nobody wants to read this monstosity every time.

    public:
        TSorter();
        TSorter(unsigned int initialCapacity);
        ~TSorter();

        void clear();
        bool insert(T value);

        // Show the first n elements, k per line using <<
        void show(unsigned int n, unsigned int k);

        // "Shuffle" the array elements
        void shuffle();

        // These are the functions you should implement for Lab 5
        // You should keep these interfaces the same, but you may add
        // other "helper" functions if necessary.
        void insertionSortI();
        void selectionSortI();
        void bubbleSortI();
        void stupidSortI();
};
#endif

