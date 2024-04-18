#include <stdio.h>

float add(float x, float y);
float subtract(float x, float y);
float multiply(float x, float y);
float divide(float x, float y);

int main() {
    // Func of ptr
    float (*operation)(float, float) = NULL;

    // Menu for the user to choose the operation
    printf("<<Welcome to my simple calculator>>\n\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    // Prompt user input
    float num1, num2;
    printf("Enter the 1st number: ");
    scanf("%f", &num1);
    printf("Enter the 2nd number: ");
    scanf("%f", &num2);

    // Set the func of ptr based on user choice
    switch (choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = subtract;
            break;
        case 3:
            operation = multiply;
            break;
        case 4:
            operation = divide;
            break;
        default:
            printf("Error: Please enter a valid choice\n");
            main();
            return 0;
    }

    // Check if the operation is valid
    if (operation == NULL) {
        printf("Invalid operation\n");
        return 0;
    }

    float result = operation(num1, num2);

    // Display the result
    switch (choice) {
        case 1:
            printf("Result of addition: %.2f\n", result);
            break;
        case 2:
            printf("Result of subtraction: %.2f\n", result);
            break;
        case 3:
            printf("Result of multiplication: %.2f\n", result);
            break;
        case 4:
            printf("Result of division: %.2f\n", result);
            break;
    }

    // Prompt for restart
    printf("Enter 'R' to start again : ");
    char option;
    scanf(" %c", &option);

    switch (option) {
        case 'R':
        case 'r':
            main(); // Restart the program
            break;
        default:
            printf("Invalid option. Exiting...\n");
            break;
    }

    return 0;
}

// Add func
float add(float x, float y) {
    return x + y;
}

// Sub func
float subtract(float x, float y) {
    return x - y;
}

// Mul func
float multiply(float x, float y) {
    return x * y;
}

// Div func
float divide(float x, float y) {
   if (y != 0){
    return x / y;
   }
   else
    {
    printf("Error : division by zero is not valid\n");
    return 0;
   }
}
