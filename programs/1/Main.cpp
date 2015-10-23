#include "Story.h"

int main() {
    Story read = Story("test.txt");
    read.save("fp.txt");
}
