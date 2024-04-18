#include <stdio.h>
#include <stdlib.h>

#define Addition(x,y)         ((x) + (y))
#define Subtraction(x,y)      ((x) - (y))
#define Multiplication(x,y)   ((x) * (y))
#define Division(x,y)         ((x) / (y))


int main() {
     printf("<<Welcome to my simple calculator>>\n\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    float num1, num2;
    printf("Enter the 1st number: ");
    scanf("%f", &num1);
    printf("Enter the 2nd number: ");
    scanf("%f", &num2);
    float result = operation(num1, num2);

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


    printf("Enter 'R' to start again : ");
    char option;
    scanf(" %c", &option);

    switch (option) {
        case 'R':
        case 'r':
            main();
            break;
        default:
            printf("Invalid option. Exiting...\n");
            break;
    }

    return 0;
}




//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<BREAK>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


/*
-Normal if statements (if, else, else if) >>> "its Execution time is runtime and its decision based on runtime condition and both branches in code are compiled"
-Compilation directives (#ifdef, #else, #endif) >>> "it works before compile so its excution time is preprocessor and its decision based on defined symbol such as macro and it compiles only the chosen block "
*/

