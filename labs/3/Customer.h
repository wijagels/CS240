#include <iostream>


class Customer {
    public:
    Customer(int);
    void add(int);
    void login();
    private:
        std::string lname;
        std::string fname;
        std::string userid;
        std::string password;
        unsigned int age;
        unsigned int streetnum;
        std::string town;
        std::string zip;
        float balance;
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
