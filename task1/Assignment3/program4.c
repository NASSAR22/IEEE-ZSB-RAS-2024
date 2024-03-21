#include <stdio.h>

void string_Copy(char *dest, const char *src) {
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

int main() {
    char source[100], destination[100];

    printf("Enter the source string: ");
    gets(source);

    string_Copy(destination, source);

    printf("Copied string: %s\n", destination);

    return 0;
}
