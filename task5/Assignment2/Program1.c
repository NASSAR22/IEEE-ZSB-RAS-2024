#include <stdio.h>

typedef enum {
    ADDITION = '+',
    SUBTRACTION = '-',
    MULTIPLICATION = '*',
    DIVISION = '/',
    BITWISE_AND = '&',
    BITWISE_OR = '|',
    LOGICAL_NOT = '!'
} Operation;

int PERFORMING(int operand1, int operand2, Operation operation) {
    int result;

    switch (operation) {
        case ADDITION:
            result = operand1 + operand2;
            break;
        case SUBTRACTION:
            result = operand1 - operand2;
            break;
        case MULTIPLICATION:
            result = operand1 * operand2;
            break;
        case DIVISION:
            result = operand1 / operand2;
            break;
        case BITWISE_AND:
            result = operand1 & operand2;
            break;
        case BITWISE_OR:
            result = operand1 | operand2;
            break;
        case LOGICAL_NOT:
            result = !operand1;
            break;
        default:
            printf("Invalid operation!\n");
            return 0;
    }

    return result;
}

int main() {
    int operand1, operand2;
    char operationChar;
    Operation operation;

    printf("Enter operand1: ");
    scanf("%d", &operand1);

    printf("Enter operand2: ");
    scanf("%d", &operand2);

    printf("Enter operation (+, -, *, /, &, |, !): ");
    scanf(" %c", &operationChar);

    operation = (Operation)operationChar;

    int result = PERFORMING(operand1, operand2, operation);

    printf("Result: %d\n", result);

    printf("Size of enum operation = %d\n", sizeof(operation));

    return 0;
}

/*
the size of enum has no change if we add new extra members
because it depends on the type of enum member (int = 4)
*/
