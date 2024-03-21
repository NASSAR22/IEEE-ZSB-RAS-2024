#include <stdio.h>

int main() {
    char str[100];

    printf("Enter a string that you want to print: ");
    gets(str);

    printf("The entered string is: %s\n", str);

    return 0;
}
