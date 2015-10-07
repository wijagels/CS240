#include <iostream>
using namespace std;

int func3(int three) {
    three = 33333;
    return(three);
}

int func2(int two) {
    two = 22222;
    return func3(two);
}

int func1(int &one) {
    one = 11111;
    return func2(one);
}

int main() {
    int zero = 0;
    int rval;
    rval = func1(zero);
    cout << "rval: " << rval << endl;
    cout << "zero: " << zero << endl;
}
