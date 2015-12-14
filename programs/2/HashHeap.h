#pragma once
#include <iostream>
#include <list>
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
        int find(const T&);
        int hash(const T&);
        void insertKey(const T&, int);
        T* arr;
    private:
        std::list<std::pair<T, int>>* ht;//hash table
        int size = 0;
        int back = 0;
        template<typename Tt>
            friend std::ostream & operator<< (std::ostream &os, const HashHeap<Tt>&);
};
#include "HashHeap.cpp"
