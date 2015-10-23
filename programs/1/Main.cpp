#include "Story.h"

int main() {
    Story read = Story("./STORIES/FreshPrince.txt");
    read.save("fp.txt");

    Story read1 = Story("./STORIES/Brady.txt");
    read1.save("br.txt");

    Story read2 = Story("./STORIES/Gilligan.txt");
    read2.save("gi.txt");
}
