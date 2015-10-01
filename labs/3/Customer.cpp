#include "Customer.h"


Customer::Customer() {
    isOk = false;
}

Customer::Customer(std::string id) {
    isOk = false;
    userid = id;
    bal = 0;
    std::string lastname, firstname, pass, usertown, zipcode, street;
    int userage, streetnumber;
    std::cout << "Enter Last Name:" << std::endl << "# ";
    std::getline(std::cin, lastname);
    if(!std::regex_match(lastname, name_re)) {
        std::cout << "Invalid last name" << std::endl;
        return;
    }
    lname = lastname;
    std::cout << "Enter First Name:" << std::endl << "# ";
    std::getline(std::cin, firstname);
    if(!std::regex_match(firstname, name_re)) {
        std::cout << "Invalid first name" << std::endl;
        return;
    }
    fname = firstname;
    std::cout << "Enter Password:" << std::endl << "# ";
    std::getline(std::cin, pass);
    if(!std::regex_match(pass, pass_re)) {
        std::cout << "Invalid password" << std::endl;
        return;
    }
    password = pass;
    std::cout << "Enter Town:" << std::endl << "# ";
    std::getline(std::cin, usertown);
    if(!std::regex_match(usertown, loc_re)) {
        std::cout << "Invalid town" << std::endl;
        return;
    }
    town = usertown;
    std::cout << "Enter Zip:" << std::endl << "# ";
    std::getline(std::cin, zipcode);
    if(!std::regex_match(zipcode, zip_re)) {
        std::cout << "Invalid zip" << std::endl;
        return;
    }
    zip = zipcode;
    std::cout << "Enter Age:" << std::endl << "# ";
    std::string temp;
    std::getline(std::cin, temp);
    userage = atoi(temp.c_str());
    if(userage < 12) {
        std::cout << "Invalid age" << std::endl;
        return;
    }
    age = userage;
    std::cout << "Enter Street Number:" << std::endl << "# ";
    std::getline(std::cin, temp);
    streetnumber = atoi(temp.c_str());
    if(streetnumber <= 0) {
        std::cout << "Invalid street number" << std::endl;
        return;
    }
    streetnum = streetnumber;
    std::cout << "Enter Street Name:" << std::endl << "# ";
    std::getline(std::cin, street);
    if(!std::regex_match(street, loc_re)) {
        std::cout << "Invalid street" << std::endl;
        return;
    }
    streetname = street;
    isOk = true;
}

Customer::Customer(std::string lname, std::string fname, std::string userid, std::string password, unsigned int age, unsigned int streetnum, std::string streetname, std::string town, std::string zip) {
    this->lname = lname;
    this->fname = fname;
    this->userid = userid;
    this->password = password;
    this->age = age;
    this->streetnum = streetnum;
    this->streetname = streetname;
    this->town = town;
    this->zip = zip;
}

Customer::~Customer() {
}

std::string Customer::getString() {
    std::string s;
    s += lname + "\n" + fname + "\n";
    s += userid + "\n" + password + "\n";
    s += std::to_string(age) + "\n" + std::to_string(streetnum) + "\n";
    s += streetname + "\n" + town + "\n" + zip;
    return s;
}

std::string Customer::getId() {
    return userid;
}

int Customer::login() {
    std::string pw;
    std::cout << "Enter password: " << std::endl << "# ";
    std::getline(std::cin, pw);
    if(!(pw == password)) {
        std::cout << "Incorrect password" << std::endl;
        return 1;
    }
    while(true) {
        std::string arg;
        std::cout << userid << ": Choose from ['Update, Passwd, View, Deposit, Withdraw, Balance, Logout']" << std::endl << "$ ";
        std::cin >> arg;
        // Don't go nuts when C-d is pressed
        if(arg == "Logout" || std::cin.eof()) {
            return 0;
        }
        else if(arg == "Update") {
            update();
        }
        else if(arg == "Passwd") {
            passwd();
        }
        else if(arg == "View") {
            view();
        }
        else if(arg == "Deposit") {
            deposit();
        }
        else if(arg == "Withdraw") {
            withdraw();
        }
        else if(arg == "Balance") {
            balance();
        }
        else {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return 0;
}

void Customer::update() {
    std::cout << "Updating account info, enter nothing to leave a field unmodified" << std::endl;
    std::string lastname, firstname, usertown, zipcode, street;
    int userage, streetnumber;
    std::cout << "Enter Last Name:" << std::endl << "# ";
    std::getline(std::cin, lastname);
    if(!lastname.empty()) {
        if(!std::regex_match(lastname, name_re)) {
            std::cout << "Invalid last name" << std::endl;
            return;
        }
        lname = lastname;
    }
    std::cout << "Enter First Name:" << std::endl << "# ";
    std::getline(std::cin, firstname);
    if(!firstname.empty()) {
        if(!std::regex_match(firstname, name_re)) {
            std::cout << "Invalid first name" << std::endl;
            return;
        }
        fname = firstname;
    }
    std::cout << "Enter Town:" << std::endl << "# ";
    std::getline(std::cin, usertown);
    if(!usertown.empty()) {
        if(!std::regex_match(usertown, loc_re)) {
            std::cout << "Invalid town" << std::endl;
            return;
        }
        town = usertown;
    }
    std::cout << "Enter Zip:" << std::endl << "# ";
    std::getline(std::cin, zipcode);
    if(!zipcode.empty()) {
        if(!std::regex_match(zipcode, zip_re)) {
            std::cout << "Invalid zip" << std::endl;
            return;
        }
        zip = zipcode;
    }
    std::cout << "Enter Age:" << std::endl << "# ";
    std::string temp;
    std::getline(std::cin, temp);
    if(!temp.empty()) {
        userage = atoi(temp.c_str());
        if(userage < 12) {
            std::cout << "Invalid age" << std::endl;
            return;
        }
        age = userage;
    }
    std::cout << "Enter Street Number:" << std::endl << "# ";
    std::string temp2;
    std::getline(std::cin, temp2);
    if(!temp2.empty()) {
        streetnumber = atoi(temp2.c_str());
        if(streetnumber <= 0) {
            std::cout << "Invalid street number" << std::endl;
            return;
        }
        streetnum = streetnumber;
    }
    std::cout << "Enter Street Name:" << std::endl << "# ";
    std::getline(std::cin, street);
    if(!street.empty()) {
        if(!std::regex_match(street, loc_re)) {
            std::cout << "Invalid street" << std::endl;
            return;
        }
        streetname = street;
    }
}

void Customer::passwd() {
    std::string old;
    std::cout << "Enter old password" << std::endl << "# ";
    std::getline(std::cin, old);
    if(!(old == password)) {
        std::cout << "Wrong password" << std::endl;
        return;
    }
    std::string npass;
    std::string npass2;
    std::cout << "Enter new password" << std::endl << "# ";
    std::getline(std::cin, npass);
    std::cout << "Enter new password again" << std::endl << "# ";
    std::getline(std::cin, npass2);
    if(!(npass == npass2)) {
        std::cout << "Passwords don't match" << std::endl;
        return;
    }
    password = npass;
    std::cout << "Password updated to " << password << std::endl;
}

void Customer::view() {
    printf("\n=== Bank of Bank ===\n");
    printf("%s %s's balance: $%.2f\n", fname.c_str(), lname.c_str(), bal);
    printf("Age: %d, id: %s, Password: %s\n", age, userid.c_str(), password.c_str());
    //TODO: state enumeration
    printf("Address: %d %s, %s, %s %s\n\n", streetnum, streetname.c_str(), town.c_str(), "NY", zip.c_str());
}

void Customer::deposit() {
    std::string dep;
    std::cout << "Enter amount to deposit" << std::endl << "$ ";
    std::cin.ignore();
    std::getline(std::cin, dep);
    float f = atof(dep.c_str());
    if(f < 0) {
        std::cout << "Invalid amount" << std::endl;
        return;
    }
    bal += f;
}

void Customer::withdraw() {
    std::string wit;
    std::cout << "Enter amount to withdraw" << std::endl << "$ ";
    std::cin.ignore();
    std::getline(std::cin, wit);
    float f = atof(wit.c_str());
    if(f < 0 || (bal - f) < 0) {
        std::cout << "Invalid amount" << std::endl;
        return;
    }
    bal -= f;
}

void Customer::balance() {
    printf("%s $%.2f\n", lname.c_str(), bal);
}
