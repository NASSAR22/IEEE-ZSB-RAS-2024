#include <stdio.h>

int main() {
    // Define variables and initialize with distinct values
    int x = 10;
    int y = 20;
    int z = 30;

    // Declare pointers
    int *p, *q, *r;

    // Assign addresses of variables to pointers
    p = &x;
    q = &y;
    r = &z;

    // Print initial values
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("z: %d\n", z);
    printf("p: %p\n", (void*)p);  // Cast p to void* for better formatting
    printf("q: %p\n", (void*)q);  // Cast q to void* for better formatting
    printf("r: %p\n", (void*)r);  // Cast r to void* for better formatting
    printf("*p: %d\n", *p);
    printf("*q: %d\n", *q);
    printf("*r: %d\n", *r);

    // Print message before swapping
    printf("\nSwapping pointers...\n");

    // Swap pointers
    r = p;
    p = q;
    q = r;

    // Print values after swapping
    printf("\nx: %d\n", x);
    printf("y: %d\n", y);
    printf("z: %d\n", z);
    printf("p: %p\n", (void*)p);
    printf("q: %p\n", (void*)q);
    printf("r: %p\n", (void*)r);
    printf("*p: %d\n", *p);
    printf("*q: %d\n", *q);
    printf("*r: %d\n", *r);

    return 0;
}
