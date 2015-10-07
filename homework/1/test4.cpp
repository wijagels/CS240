#include <cstdio>
int main() {
    int i = 123;
    int *ip = &i;
    int **ipp = &ip;
    printf("%d", **ipp);

}
