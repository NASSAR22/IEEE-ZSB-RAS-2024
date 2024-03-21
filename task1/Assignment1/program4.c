#include <stdio.h>

long Add_Numbers(long *, int);

int main() {
    int count;
    long numbers[100];
    long sum;

    // Prompt user for input
    printf("Enter the number of elements to be added: ");
    scanf("%d", &count);

    printf("Enter %d numbers:\n", count);
    for (int i = 0; i < count; i++) {
        printf("Number %d: ", i + 1);
        scanf("%ld", &numbers[i]);
    }

    // Print the sum of the entered numbers
        sum = Add_Numbers(numbers, count);
        printf("The sum is %ld\n\n", sum);
    return 0;
}

// Function to add numbers using call by reference
long Add_Numbers(long *nums, int count) {
    long sum = 0;
    for (int i = 0; i < count; i++) {
        sum += *nums;
        nums++;
    }
    return sum;
}
