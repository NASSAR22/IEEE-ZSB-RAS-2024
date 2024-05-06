#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char unique[100];
    int i, j, len, is_unique;


    while (1) {
        printf("Enter a string: ");
        scanf("%s", input);


        len = strlen(input);
        j = 0;

        for (i = 0; i < len; i++) {
            is_unique = 1;

            for (int k = 0; k < j; k++) {
                if (input[i] == unique[k]) {
                    is_unique = 0;
                    break;
                }
            }

            if (is_unique) {
                unique[j] = input[i];
                j++;
            }
        }

        unique[j] = '\0';
        printf("Unique characters in the string: %s\n", unique);
    }

    printf("Stop code entered. Exiting program.\n");
    return 0;
}