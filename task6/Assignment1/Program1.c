#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *ptr1;
    int *ptr2; 
    int *ptr3;

    // Allocate memory using malloc
    ptr1 = (int *)malloc(sizeof(int));
    if (ptr1 == NULL) 
    {
        printf("Memory allocation failed for ptr1\n");
    } 
    else 
    {
        *ptr1 = 25;
        printf("Value of ptr1: %d\n", *ptr1);
    }

    // Allocate memory using calloc
    ptr2 = (int *)calloc(1, sizeof(int));
    if (ptr2 == NULL) 
    {
        printf("Memory allocation failed for ptr2\n");
    } 
    else 
    {
        *ptr2 = 50;
        printf("Value of ptr2: %d\n", *ptr2);
    }

    // Reallocate memory using realloc
    ptr3 = (int *)realloc(ptr3, 3 * sizeof(int));
    if (ptr3 == NULL) 
    {
        printf("Memory reallocation failed for ptr3\n");
    } 
    else
    {
        ptr3[2] = 100;
        printf("Values of ptr3 after reallocation: %d, %d, %d\n", ptr3[0], ptr3[1], ptr3[2]);
    }  

    // Free allocated memory
    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}