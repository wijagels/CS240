#include <iostream>
using namespace std;
void showFloatArray(float f1[10]) {
    for (int i=0; i < 10; i++)
        cout << " " << f1[i];
    cout << endl;
}
float *getFloatArrayOne() {
    float *floatArray = new float[10];
    for (int i=0; i < 10; i++)
        floatArray[i] = (float) i;
    return(floatArray);
}
float *getFloatArrayTwo() {
    float myFloatArray[10];
    float *floatArray = myFloatArray;
    for (int i=0; i < 10; i++)
        floatArray[i] = (float) i;
    return(floatArray);
}
int main() {
    float *f1 = getFloatArrayOne();
    float *f2 = getFloatArrayTwo();
    showFloatArray(f1);
    showFloatArray(f2);
    delete(f1);
    delete(f2);
}
