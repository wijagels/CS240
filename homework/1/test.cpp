#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i;
    char myCharArray[51] = "This string right here contains exactly 50 chars. ";
    double myDoubleArray[4] = {100, 101, 102, 103};

    char *cp, *cbp;
    double *dp, *dbp;

    dp = &myDoubleArray[0];
    dbp = myDoubleArray;
    cp = &myCharArray[0];
    cbp = myCharArray;
    printf("%d, %p, %p, %p, %p\n", i, dp, dbp, cp, cbp);
    while ((cp - cbp) < sizeof(myCharArray)) {
        cp++; dp++;
    }
    cout << "Without cast: " << (dp - dbp) << endl;
    cout << " Cast 1: " << ((int *) dp - (int *) dbp) << endl;
    cout << " Cast 2: " << ((int) dp - (int) dbp) << endl;
    printf("%d, %p, %p, %p, %p\n", i, dp, dbp, cp, cbp);
}
