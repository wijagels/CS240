#include <iostream>
#include <stdio.h>

void update(std::string &lname,std::string &fname, std::string &sname, std::string &town, std::string &zip, int &age, int &streetNumber);

void resetBal(float &bal);

void balance(const float &bal);

void deposit(float &bal);

void withdraw(float &bal);

void view(const std::string &lname, const std::string &fname, const std::string &sname, const std::string &town, const std::string &zip, const int &age, const int &streetNumber, const float bal);
