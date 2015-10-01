#include "Bank.h"

int main(int argc, const char* argv[]) {
    switch(argc) {
        case 2:
        {
            // Stringstream would be ~20x slower than atoi.
            Bank *b = new Bank(atoi(argv[1]));
            b -> cmdLoop();
            delete b;
            return 0;
        }
        case 3:
        {
            Bank *b = new Bank(atoi(argv[1]), argv[2]);
            b -> cmdLoop();
            delete b;
            return 0;
        }
        default:
            std::cout << "Invalid number of arguments" << std::endl;
            return 2; // Code for bad arguments
    }
}

Bank::Bank(int i) {
    if(i <= 0)
        throw std::invalid_argument("Negative size is not valid or NaN");
    size = i;
}

Bank::Bank(int i, const char* file) {
    if(i <= 0) {
        throw std::invalid_argument("Negative size is not valid or NaN");
    }
    size = i;
    std::ifstream f;
    f.open(file);
    if(f.is_open()) {
        std::cout << "File " << file << " opened" << std::endl;
    }
    f.close();
}

Bank::~Bank() {
    std::cout << "Bank has failed, contact the FDIC" << std::endl;
}

int Bank::cmdLoop() {
    while(true) {
        std::string arg;
        std::cout << "Choose from ['New', 'Login', 'Save', 'Load', 'Quit']" << std::endl << "$ ";
        std::getline(std::cin, arg);
        // Don't go nuts when C-d is pressed
        if(arg == "Quit" || std::cin.eof()) {
            return 0;
        }
        else if(arg == "Login") {
            login();
        }
        else if(arg == "New") {
            newAccount();
        }
    }
    return 1;
}

int Bank::login() {
    std::string id;
    std::cout << "Enter user id:" << std::endl << "# ";
    std::getline(std::cin, id);
    for(Customer& c : customers) { // Compiler will warn about C++11
        if(c.getId() == id) {
            c.login();
            return 0;
        }
    }
    std::cout << "User id not found" << std::endl;
    return 1;
}

int Bank::newAccount() {
    if(curSize() >= size) {
        std::cout << "Yellen says no more customers allowed!" << std::endl;
        return 1;
    }
    std::string id;
    std::cout << "Enter user id:" << std::endl << "# ";
    std::getline(std::cin, id);
    if(!std::regex_match(id, id_re)) {
        std::cout << "Invalid user id format" << std::endl;
        return 1;
    }
    for(Customer& c : customers) {
        if(c.getId() == id) {
        }
    }
    Customer *c = new Customer(id);
    customers.push_back(*c);
    return 0;
}

unsigned int Bank::curSize() {
    unsigned int s = 0;
    for(Customer& c : customers) {
        if(c.getId().empty())
            s++;
        else
            return s;
    }
    return s;
}
