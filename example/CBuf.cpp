#include <iostream>

class IntWrapper {
    public:
        IntWrapper() {
            data = -1;
        }
        IntWrapper(int i) {
            data = i;
        }
        /**
         * Things don't actually need to be cleaned up explicitly here,
         * but if you had a class that did need it, you're going to have
         * to call its destructor or else things are going to get lost.
         * For example, if we had a circular buffer of fstreams, we
         * would absolutely need to explicitly call the destructor,
         * otherwise we'd end up with open files that are inaccessible.
         */
        ~IntWrapper() {
            std::cout << "Destructor called" << std::endl;
        }
        int getData() {
            return data;
        }
    private:
        int data;
};

class CircBuffer {
    public:
        CircBuffer() {
            mem = (IntWrapper *)(operator new(sizeof(IntWrapper)));
            size = 1;
        }
        CircBuffer(int s) {
            mem = (IntWrapper *)(operator new(s * sizeof(IntWrapper)));
            size = s;
        }
        void insert(int i) {
            std::cout << "Inserting at " << &mem[counter] << std::endl;
            mem[counter].~IntWrapper(); // Destructs whatever is being overwritten
            new(&mem[counter]) IntWrapper(i);
            counter++;
            counter %= size;
        }
        int read() {
            IntWrapper* pt = &mem[counter];
            int d = mem[rcounter++].getData();
            rcounter %= size;
            return d;
        }
        IntWrapper* mem;
        int size;
        int counter = 0;
        int rcounter = 0;
        ~CircBuffer() {
            std::cout << "CircBuffer destruct" << std::endl;
            operator delete(mem); // This is required, otherwise there's a leak
        }
};

int main() {
    CircBuffer* b = new CircBuffer(10);
    std::cout << sizeof(b->mem) << " " << sizeof(IntWrapper) << std::endl;
    for(int i=0;i<14;i++) {
        b->insert(i);
        /*
         * Insert 14 ints to demonstrate what happens when
         * the end of the buffer is reached
         */
    }
    for(int i = 0;i<10; i++) {
        std::cout << b->read() << std::endl;
    }
    delete(b);
    return 1;
}
