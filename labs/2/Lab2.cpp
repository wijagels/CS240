#include "JagelsWilliamAccountFunctions.h"

int main() {
    std::string lname, fname, sname, town, zip;
    int age, streetNumber;
    float bal = 0;
    std::string arg;

    while(true) {
        std::cout << "Enter a command." << std::endl;
        std::cout << "Choose from [\"New\" \"View\" \"Update\" \"Deposit\" \"Withdraw\" \"Balance\" \"Quit\"]" << std::endl << ": ";
        std::cin >> arg;

        if(arg == "Quit") {
            lname.clear();
            fname.clear();
            sname.clear();
            town.clear();
            zip.clear();
            return 0;
        }
        else if(arg == "New") {
            update(lname, fname, sname, town, zip, age, streetNumber);
            resetBal(bal);
        }
        else if(arg == "Update") {
            update(lname, fname, sname, town, zip, age, streetNumber);
        }
        else if(arg == "View") {
            view(lname, fname, sname, town, zip, age, streetNumber, bal);
        }
        else if(arg == "Deposit") {
            deposit(bal);
        }
        else if(arg == "Withdraw") {
            withdraw(bal);
        }
        else if(arg == "Balance") {
            balance(bal);
        }
        else {
            std::cout << "Command not recognized. Please try again." << std::endl;
        }
    }
}
