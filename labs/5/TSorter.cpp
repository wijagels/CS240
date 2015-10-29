#include <iostream>
using namespace std;

#include "TSorter.h"

template <typename T>
TSorter<T>::TSorter() {
}

template <typename T>
void TSorter<T>::clear() {
    array.clear();
    return;
}

template <typename T>
bool TSorter<T>::insert(T element) {
    array.push_back(element);
    return true;
}

template <typename T>
TSorter<T>::~TSorter() {
}

// Shuffle array elements
template <typename T>
void TSorter<T>::shuffle() {
    std::random_shuffle(array.begin(), array.end());
}

// Show the first n elements, k per line, using <<
template <typename T>
void TSorter<T>::show(unsigned int n, unsigned int k) {
    unsigned int c = 0;
    cout << endl;
    for(auto i : array) {
        cout << i << " ";
        if(!(c % k) && c != 0)
            cout << endl;
        if(c > n)
            break;
        ++c;
    }
    cout << endl <<endl;
}

// Iterative Insertion Sort
template <typename T>
void TSorter<T>::insertionSortI() {
    for(tIter i = array.begin() + 1;i < array.end();i++) {
        T cur = *i;
        tIter k = i-1;
        while(k >= array.begin() && *k > cur) {
            iter_swap(k+1, k);
            k--;
        }
    }
}

// Iterative Selection Sort
template <typename T>
void TSorter<T>::selectionSortI() {
    for(tIter i = array.begin();i != array.end()-1;i++) {
        tIter minimum = i;
        tIter k;
        for(k=i+1;k != array.end();k++)
            if(*k < *minimum)
                minimum = k;
        if(minimum != k)
            iter_swap(minimum, i);
    }
}

// Iterative Bubble Sort
template <typename T>
void TSorter<T>::bubbleSortI() {
    for(tIter i=array.begin();i != array.end()-1;i++)
        for(tIter k = array.begin();k != array.end()-1;k++)
            if(*k > *(k+1))
                iter_swap(k, k+1);
}

// Iterative Stupid Sort
// O(n) best case runtime!
template <typename T>
void TSorter<T>::stupidSortI() {
    unsigned long long i = 0;
    while(!std::is_sorted(array.begin(), array.end())) {
        shuffle();
        ++i;
    }
    setlocale(LC_NUMERIC, "");
    printf("Only took %'lld tries!\n", i);
}

