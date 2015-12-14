#ifndef hhcp
#define hhcp
#include "HashHeap.h"

template <typename T>
HashHeap<T>::HashHeap(int size) {
    arr = new T[size];
    ht = new std::list<std::pair<T, int>>[size];
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
    insertKey(item, back);
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
    if(i >= back)
        return;
    if(arr[i] < arr[2*i+1])
        swap(i, 2*i+1);
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
    int inf = hash(f);
    int ins = hash(s);
    for(auto i : ht[inf]) {
        if(i.first == f)
            i.second = second;
    }
    for(auto i : ht[ins]) {
        if(i.first == s)
            i.second = first;
    }
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
    heapify_down(0);
    return popped;
}

template <typename T>
int HashHeap<T>::find(const T& item) {
    for(int i=0;i<size;i++)
        if(arr[i] == item)
            return i;
    int index = hash(item);
    for(auto el : ht[index]) {
        if(el.first == item)
            return el.second;
    }
    // for(int i=0;i<back;i++) {
    //     if(arr[i] == item)
    //         return i;
    // }
    throw 0;
}

template <typename T>
int HashHeap<T>::hash(const T& item) {
    int sum = 0;
    for(char c : item.title)
        sum += c;
    return sum % size;
}

template <typename T>
void HashHeap<T>::insertKey(const T& item, int index) {
    int i = hash(item);
    for(auto it : ht[i]) {
        if(it.first == item) {
            it.second = index;
            return;
        }
    }
    ht[i].push_back(std::pair<T, int>(item, index));
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
        os << hh.arr[i] << " ";
    return os;
}
#endif
