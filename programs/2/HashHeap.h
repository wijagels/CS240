#pragma once
#include <iostream>
#include "Song.h"

template <typename T>
class HashHeap {
    public:
        HashHeap();
        HashHeap(int);
        bool insert(const T&);
        void heapify_up(int);
        void heapify_down(int);
        void swap(int, int);
        T max();
        T pop_max();
        T& find(const T&);
    private:
        T* arr;
        int size = 0;
        int back = 0;
        //std::unordered_map<T, int> index;
        template<typename Tt>
            friend std::ostream & operator<< (std::ostream &os, const HashHeap<Tt>&);
};
#include "HashHeap.cpp"
