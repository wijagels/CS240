#include "Customer.h"


Customer::Customer() {
}

Customer::Customer(std::string id) {
    userid = id;
}

Customer::~Customer() {
}

std::string Customer::getId() {
    return userid;
}

int Customer::login() {
    std::string pw;
    std::cout << "Enter password: " << std::endl << "# ";
    std::getline(std::cin, pw);
    while(true) {
        std::string arg;
        std::cout << "Choose from ['New', 'Login', 'Save', 'Load', 'Quit']" << std::endl << "$ ";
        std::cin >> arg;
        // Don't go nuts when C-d is pressed
        if(arg == "Quit" || std::cin.eof()) {
            return 0;
        }
    }
    return 0;
}
