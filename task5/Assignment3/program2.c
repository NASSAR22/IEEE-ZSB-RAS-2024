#include <stdio.h>
//UNCOMMENT LINE 3 OR 4 TO CHOOSE THE OPERATION(*.')
//#define ADDITION
// #define SUBTRACTION  // Uncomment for subtraction (optional)

#define add(x, y)           (x) + (y)
#define subtract(x, y)      (x) - (y)

int main() {
  int n1, n2, result;
  char operation;

  printf("Enter two integer values: ");
  scanf("%d %d", &n1, &n2);

  printf("Enter an operation (+ or -): ");
  scanf(" %c", &operation); // Extra space to consume whitespace

  #ifdef ADDITION
    result = add(n1, n2);
    printf("%d + %d = %d\n", n1, n2, result);
  #elif defined(SUBTRACTION)
    result = subtract(n1, n2);
    printf("%d - %d = %d\n", n1, n2, result);
  #else
    printf("Error: No operation defined. Please uncomment line '3' or '4' to define ADDITION or SUBTRACTION macro.\n");
  #endif

  return 0;
}
