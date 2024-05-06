#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char name[MAX_LENGTH];
    char most_repeated_char;
    int max_length;
    int char_count[256] = {0};
    int max_frequency = 0;

    printf("Enter the maximum length of the name: ");
    scanf("%d", &max_length);

    printf("Enter the name: ");
    scanf(" %[^\n]", name);

    printf("Entered name: %s\n", name);

    // Calculate frequency of each character
    for (int i = 0; i < strlen(name); i++) {
        char_count[(int)name[i]]++;
    }

    // check the most repeated character
    for (int i = 0; i < 256; i++) {
        if (char_count[i] > max_frequency) {
            max_frequency = char_count[i];
            most_repeated_char = (char)i;
        }
    }

    printf("Most repeated character is: %c\n", most_repeated_char);
    printf("Frequency: %d\n", max_frequency);

    return 0;
}