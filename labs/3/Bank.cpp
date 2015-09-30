#include "Bank.h"

int main(int argc, const char* argv[]) {
    printf("argc: %d, argv: [", argc);
    for(int i=0;i<argc;i++)
        printf("%s, ", argv[i]);
    std::cout << "]" << std::endl;
    Customer *c = new Customer(1);
    c -> add(1);
}
