#include <stdio.h>

int main(){
    int x = 0x123456;
    char *ptr = &x;

    printf("Before Operation:\n");

    printf("*ptr = 0x%X\n\n", *ptr);


    printf("After Operation:\n");

    printf("*ptr++ = 0x%X\n", *ptr++); // First get the value then ptr incrementing ====> ptr = 0x56

    printf("*++ptr = 0x%X\n", *++ptr); // First ptr incremnting then get the value  ====> ptr = 0x12

    printf("++*ptr = 0x%X\n", ++*ptr); // First get the value then ptr incrementing ====> ptr = 0x13
}
