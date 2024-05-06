#include <stdio.h>
#define mySizeof(type) (char )(&type+1)-(char)(&type)
inline inline_size(int type) { return (char )(&type+1)-(char)(&type); }

int main() {
    int x;
    char y;
    printf("Size of int: %ld\n", mySizeof(x));
    printf("Size of char: %ld\n", mySizeof(y));

    printf("Size of int: %d\n", inline_size(x));
    printf("Size of char: %d\n", inline_size(y));

    return 0;
}