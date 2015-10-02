#include "Bank.h"

int main(int argc, const char* argv[]) {
    switch(argc) {
        case 2:
        {
            // Stringstream would be ~20x slower than atoi.
            Bank *b = new Bank(atoi(argv[1]));
            b -> cmdLoop();
            return 0;
        }
        case 3:
        {
            Bank *b = new Bank(atoi(argv[1]), argv[2]);
            b -> cmdLoop();
            return 0;
        }
        default:
            std::cout << "Invalid number of arguments" << std::endl;
            return 2; // Code for bad arguments
    }
}

Bank::Bank(int i) {
    if(i <= 0) {
        throw std::invalid_argument("Negative size is not valid or NaN");
    }
    if(i > MAX_CUSTOMERS) {
        throw std::invalid_argument("Max customers is too large");
    }
    size = i;
}

Bank::Bank(int i, const char* file) {
    if(i <= 0) {
        throw std::invalid_argument("Negative size is not valid or NaN");
    }
    if(i > MAX_CUSTOMERS) {
        throw std::invalid_argument("Max customers is too large");
    }
    size = i;
    std::string b(file);
    load(b);
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
        if(std::cin.eof()) {
            return 0;
        }
        if(arg == "Quit") {
            while(true) {
                std::cout << "Save before quitting? [yes/no]" << std::endl;
                std::string ans;
                getline(std::cin, ans);
                if(ans == "no")
                    return 0;
                else if(ans == "yes") {
                    save();
                    return 0;
                }
            }
        }
        else if(arg == "New") {
            newAccount();
        }
        else if(arg == "Login") {
            login();
        }
        else if(arg == "Save") {
            save();
        }
        else if(arg == "Load") {
            load();
        }
        else {
            std::cout << "Invalid command!" << std::endl;
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
            std::cout << "User already exists" << std::endl;
            return 1;
        }
    }
    Customer *c = new Customer(id);
    if(c -> isOk) {
        customers.push_back(*c);
        return 0;
    }
    return 1;
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

void Bank::save() {
    std::cout << "Enter filename: " << std::endl;
    std::string filename;
    std::getline(std::cin, filename);
    std::ofstream out;
    out.open(filename);
    for(Customer& c: customers) {
        if(!c.getId().empty())
            out << c.getString() << std::endl;
    }
    out.close();
}

void Bank::load() {
    std::cout << "Enter filename: " << std::endl;
    std::string filename;
    std::getline(std::cin, filename);
    load(filename);
}

void Bank::load(std::string filename) {
    std::ifstream in;
    in.open(filename);
    if(in.is_open()) {
        while(!in.eof()) {
            std::string lname;
            std::string fname;
            std::string userid;
            std::string password;
            unsigned int age;
            unsigned int streetnum;
            std::string streetname;
            std::string town;
            std::string zip;
            std::string state;

            std::string temp;
            std::string temp2;

            getline(in, lname);
            getline(in, fname);
            getline(in, userid);
            getline(in, password);
            getline(in, temp);
            age = atoi(temp.c_str());
            getline(in, temp2);
            streetnum = atoi(temp2.c_str());
            getline(in, streetname);
            getline(in, town);
            getline(in, zip);
            getline(in, state);
            State st = makeState(state);
            if(curSize() >= size) {
                std::cout << "Yellen says no more customers allowed!" << std::endl;
                return;
            }
            for(Customer& c : customers) {
                if(c.getId() == userid) {
                    std::cout << "User already exists" << std::endl;
                    return;
                }
            }
            Customer *c = new Customer(lname, fname, userid, password, age, streetnum, streetname, town, zip, st);
            customers.push_back(*c);
        }
    }
}
