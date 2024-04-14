#include <stdio.h>

void increment(int *value) {
    (*value)++;
}

int main() {
    int x = 1;
    void (*ptr)(int *);

    ptr = increment;
    printf("Before increment: %d\n", x);

    ptr(&x);

    printf("After increment: %d\n", x);

    return 0;
}
