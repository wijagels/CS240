#include "Customer.h"
#include <stdio.h>
#include <fstream>
#include <vector>


class Bank {
    public:
        Bank(int);
        Bank(int, const char*);
        ~Bank();
        int cmdLoop();
    private:
        int newAccount();
        int login();
        void save();
        void load();
        unsigned int curSize();
        /* Variables */
        unsigned int size;
        std::vector<Customer> customers;
};
