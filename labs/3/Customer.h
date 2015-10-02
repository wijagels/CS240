#pragma once
#include <iostream>
#include <stdlib.h>
#include <regex>

const std::regex id_re("^[A-Za-z0-9]{5,10}$");
const std::regex name_re("^[A-Za-z]+$");
const std::regex zip_re("^\\d{5}$");
const std::regex pass_re("^(?=.*[ -~])(?=.*[ -@[-`{-~]).{6,}$");
const std::regex loc_re("^[\\w\\t ]+$");

enum State {
    NY,
    PA,
    CT,
    RI,
    MA,
    VT,
    NH,
    ME,
    WRONG
};

std::string printState(State);
State makeState(std::string);

class Customer {
    public:
        Customer();
        Customer(std::string);
        Customer(std::string, std::string, std::string, std::string, unsigned int, unsigned int, std::string, std::string, std::string, State);
        ~Customer();
        std::string getString();
        int login();
        std::string getId();
        bool isOk;
    private:
        void update();
        void passwd();
        void view();
        void deposit();
        void withdraw();
        void balance();
        /* Variables */
        std::string lname;
        std::string fname;
        std::string userid;
        std::string password;
        unsigned int age;
        unsigned int streetnum;
        std::string streetname;
        std::string town;
        std::string zip;
        float bal;
        State state;
};
