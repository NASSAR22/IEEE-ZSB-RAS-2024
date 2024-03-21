#include <stdio.h>

int compare_Strings(const char *str1, const char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        // Strings are not equal
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
        // Strings are equal
        if (str1[i] == '\0' && str2[i] == '\0') {
            return 1;
    }

    return 0;
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    // Compare the strings and print the result
    if (compare_Strings(str1, str2)) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}
