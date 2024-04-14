#include <stdio.h>

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int *ptr = arr; // Pointer to the first element of the array

  printf("Array elements using pointer:\n");
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    printf("%d ", *(ptr + i));
  }
  printf("\n\n");

  return 0;
}
