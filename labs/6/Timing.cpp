// For fun try compiling with g++ -O timing.cpp and also g++ -g timing.cpp and running each one.
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include "BinarySearchTree.h"

void dankMemes(int);
void dankerMemes(int);
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

using namespace std;
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    dankMemes(50000);
    dankerMemes(50000);

    dankMemes(75000);
    dankerMemes(75000);

    dankMemes(100000);
    dankerMemes(100000);
}

void dankMemes(int z) {
    BST b = BST();

    for(int i=1;i<=z;i++) {
        b.insert(i);
    }

    struct timeval start, finish;
    gettimeofday(&start, NULL);

    int k = 0;
    for(int i=0;i<=z;i++) {
        if(i % 10000 == 0) {
            b.find(i);
            ++k;
        }
    }


    gettimeofday(&finish, NULL);
    double totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << z << "[sequential] find(multiples of 10,000): " << totalTime << "s, "
        << totalTime/k << " sec/find" << endl;

    for(int i=0;i<=z;i++) {
        if(i%4 == 0)
            b.remove(i);
    }
    gettimeofday(&start, NULL);

    k = 0;
    for(int i=0;i<=z;i++) {
        if(i % 10000 == 0) {
            b.find(i);
            ++k;
        }
    }


    gettimeofday(&finish, NULL);
    totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << z << "[sequential] find(multiples of 10,000): " << totalTime << "s, "
        << totalTime/k << " sec/find" << endl;


    for(int i=0;i<=z;i++) {
        if(i%2 == 0)
            b.remove(i);
    }
    gettimeofday(&start, NULL);

    k = 0;
    for(int i=0;i<=z;i++) {
        if(i % 10000 == 0) {
            b.find(i);
            ++k;
        }
    }


    gettimeofday(&finish, NULL);
    totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << z << "[sequential] find(multiples of 10,000): " << totalTime << "s, "
        << totalTime/k << " sec/find" << endl;
}

void dankerMemes(int z) {
    BST b = BST();

    vector<int> v;

    for(int i=1;i<=z;i++){
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for(int i:v) {
        b.insert(i);
    }

    struct timeval start, finish;
    gettimeofday(&start, NULL);

    int k = 0;
    for(int i=0;i<=z;i++) {
        if(i % 10000 == 0) {
            b.find(i);
            ++k;
        }
    }

    gettimeofday(&finish, NULL);
    double totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << z << "[random] find(multiples of 10,000): " << totalTime << "s, "
        << totalTime/k << " sec/find" << endl;

    for(int i=0;i<=z;i++) {
        if(i%4 == 0)
            b.remove(i);
    }
    gettimeofday(&start, NULL);

    k = 0;
    for(int i=0;i<=z;i++) {
        if(i % 10000 == 0) {
            b.find(i);
            ++k;
        }
    }


    gettimeofday(&finish, NULL);
    totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << z << "[random] find(multiples of 10,000): " << totalTime << "s, "
        << totalTime/k << " sec/find" << endl;

    for(int i=0;i<=z;i++) {
        if(i%2 == 0)
            b.remove(i);
    }
    gettimeofday(&start, NULL);

    k = 0;
    for(int i=0;i<=z;i++) {
        if(i % 10000 == 0) {
            b.find(i);
            ++k;
        }
    }


    gettimeofday(&finish, NULL);
    totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << z << "[random] find(multiples of 10,000): " << totalTime << "s, "
        << totalTime/k << " sec/find" << endl;
}

void test1() {
    BST b = BST();

    struct timeval start, finish;
    gettimeofday(&start, NULL);

    for(int i=1;i<=10000;i++){
        b.insert(i);
    }

    gettimeofday(&finish, NULL);
    double totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << "10,000 sequential: " << totalTime << "s, "
        << totalTime/10000 << " sec/insertion" << endl;
}

void test2() {
    BST b = BST();
    vector<int> v;

    for(int i=1;i<=10000;i++){
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for(int i:v) {
        b.insert(i);
    }

    struct timeval start, finish;
    gettimeofday(&start, NULL);

    for(int i : v) {
        b.insert(i);
    }

    gettimeofday(&finish, NULL);
    double totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << "10,000 random: " << totalTime << "s, "
        << totalTime/10000 << " sec/insertion" << endl;
}

void test3() {
    BST b = BST();
    for(int i=1;i<=10000;i++) {
        b.insert(i);
    }
    struct timeval start, finish;
    gettimeofday(&start, NULL);

    for(int i=1;i<=10000;i++) {
        b.find(i);
    }

    gettimeofday(&finish, NULL);
    double totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << "10,000 sequential: " << totalTime << "s, "
        << totalTime/10000 << " sec/find" << endl;
}

void test4() {
    BST b = BST();
    vector<int> v;

    for(int i=1;i<=10000;i++){
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for(int i:v) {
        b.insert(i);
    }

    struct timeval start, finish;
    gettimeofday(&start, NULL);

    for(int i=1;i<=10000;i++) {
        b.find(i);
    }

    gettimeofday(&finish, NULL);
    double totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << "10,000 random: " << totalTime << "s, "
        << totalTime/10000 << " sec/find" << endl;
}

void test5() {
    BST b = BST();
    for(int i=1;i<=10000;i++) {
        b.insert(i);
    }

    struct timeval start, finish;
    gettimeofday(&start, NULL);

    for(int i=1;i<=10000;i++) {
        b.remove(i);
    }

    gettimeofday(&finish, NULL);
    double totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << "10,000 sequential: " << totalTime << "s, "
        << totalTime/10000 << " sec/removal" << endl;
}


void test6() {
    BST b = BST();
    vector<int> v;

    for(int i=1;i<=10000;i++){
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for(int i:v) {
        b.insert(i);
    }


    struct timeval start, finish;
    gettimeofday(&start, NULL);

    for(int i=1;i<=10000;i++) {
        b.remove(i);
    }

    gettimeofday(&finish, NULL);
    double totalTime =
        (double)((double)(finish.tv_sec - start.tv_sec) * 1000000 +
                (double)(finish.tv_usec - start.tv_usec)) /
        (double)1000000;
    cout << "10,000 random: " << totalTime << "s, "
        << totalTime/10000 << " sec/removal" << endl;
}
