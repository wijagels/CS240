#pragma once
#include <iostream>
#include <stdlib.h>
#include <regex>

const std::regex id_re("^[A-Za-z0-9]{5,10}$");
const std::regex name_re("^[A-Za-z]+$");
const std::regex zip_re("^\\d{5}$");
const std::regex pass_re("^(?=.*[ -~])(?=.*[ -@[-`{-~]).{6,}$");

class Customer {
    public:

        Customer();
        Customer(std::string);
        ~Customer();
        int login();
        std::string getId();
    private:
        void update();
        void passwd();
        void view();
        void deposit(float);
        void withdraw(float);
        void balance();
        /* Variables */
        std::string lname;
        std::string fname;
        std::string userid;
        std::string password;
        unsigned int age;
        unsigned int streetnum;
        std::string town;
        std::string zip;
        float bal;
        enum State {
            NY,
            PA,
            CT,
            RI,
            MA,
            VT,
            NH,
            ME
        };
};
