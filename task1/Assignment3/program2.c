#include <stdio.h>

int main() {
    char str[100];
    int i = 0;

    printf("Input the string : ");

    gets(str);

    printf("The characters of the string are : \n");

    while (str[i] != '\0') {
        printf("%c  ", str[i++]);
    }

	return 0;
}
