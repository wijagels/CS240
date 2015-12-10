#ifndef hhcp
#define hhcp
#include "HashHeap.h"

template <typename T>
HashHeap<T>::HashHeap(int size) {
    arr = new T[size];
    this->size = size;
}

template <typename T>
HashHeap<T>::HashHeap() {
}

template <typename T>
bool HashHeap<T>::insert(const T& item) {
    if(back >= size)
        return false;
    arr[back] = item;
    heapify_up(back);
    back++;
    return true;
}

template <typename T>
void HashHeap<T>::heapify_up(int i) {
    while(i > 0) {
        if(arr[i] > arr[(i-1)/2])
            swap(i, (i-1)/2);
        i = (i-1) / 2;
    }
}


template <typename T>
void HashHeap<T>::heapify_down(int i) {
    if(arr[i] < arr[2*i+1])
        swap(i, 2*i+1);
    return;
    if(arr[i] < arr[2*i+2])
        swap(i, 2*i+2);
    return;
}

template <typename T>
void HashHeap<T>::swap(int first, int second) {
    T f, s;
    f = arr[first];
    s = arr[second];
    arr[first] = s;
    arr[second] = f;
}

template <typename T>
T HashHeap<T>::max() {
    if(back == 0)
        throw 1738;
    return arr[0];
}

template <typename T>
T HashHeap<T>::pop_max() {
    T popped = arr[0];
    swap(0, back-1);
    back--;
}

template <typename T>
T& HashHeap<T>::find(const T& item) {
    return std::find(std::begin(arr), std::end(arr), item);
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const HashHeap<T>& hh) {
    for(int i=0;i < hh.back;i++) {
        i++;
        if(i&&(!(i&(i-1))))//Code golfing, checks for power of 2
            os << std::endl;
        i--;
        os << hh.arr[i] << " ";
    }
    os << std::endl << "Array representation" << std::endl;
    for(int i=0;i<hh.back;i++)
        std::cout << hh.arr[i] << " ";
    return os;
}
#endif
