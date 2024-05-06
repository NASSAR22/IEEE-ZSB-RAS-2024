#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1;
    int *ptr2;
    int *ptr3;
    int *ptr4;

    // Allocate memory using malloc
    ptr1 = (int *)malloc(sizeof(int));
    if (ptr1 == NULL)
    {
        printf("Memory allocation failed for ptr1\n");
        return 1;
    }
    *ptr1 = 25;
    printf("Value of ptr1: %d\n", *ptr1);

    // Allocate memory using calloc
    ptr2 = (int *)calloc(1, sizeof(int));
    if (ptr2 == NULL)
    {
        printf("Memory allocation failed for ptr2\n");
        free(ptr1);
        return 1;
    }
    *ptr2 = 50;
    printf("Value of ptr2: %d\n", *ptr2);

    // Free one memory space and allocate a fourth space with a bigger size
    free(ptr2);
    ptr4 = (int *)malloc(3 * sizeof(int));
    if (ptr4 == NULL)
    {
        printf("Memory allocation failed for ptr4\n");
        free(ptr1);
        return 1;
    }
    ptr4[0] = 75;
    ptr4[1] = 100;
    ptr4[2] = 125;
    printf("Values of ptr4: %d, %d, %d\n", ptr4[0], ptr4[1], ptr4[2]);

    // Free allocated memory
    free(ptr1);
    free(ptr4);

    return 0;
}