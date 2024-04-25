#include <stdio.h>
//UNCOMMENT LINE 3 OR 4 TO CHOOSE THE SORT OF ARRAY(*.')
//#define ASCENDING_SORT
//#define DESCENDING_SORT


void get_array_from_user(int arr[], int size) {
  printf("Enter %d integer values:\n", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort(int arr[], int size, int ascending) {
  for (int i = 0; i < size - 1; i++) {
    int min_or_max_index = i;
    for (int j = i + 1; j < size; j++) {
      if (ascending) {
        if (arr[j] < arr[min_or_max_index]) {
          min_or_max_index = j;
        }
      } else {
        if (arr[j] > arr[min_or_max_index]) {
          min_or_max_index = j;
        }
      }
    }
    swap(&arr[i], &arr[min_or_max_index]);
  }
}

int main() {
  int arr[100];
  int size;

  printf("Enter the size of the array (max 100): ");
  scanf("%d", &size);

  get_array_from_user(arr, size);

  #ifdef ASCENDING_SORT
    selection_sort(arr, size, 1); // 1 for ascending sort
    printf("Sorted array (ascending): ");
  #elif defined(DESCENDING_SORT)
    selection_sort(arr, size, 0); // 0 for descending sort
    printf("Sorted array (descending): ");
  #else
    printf("Error: No sorting order defined. Please uncomment line '3' or '4' to define ASCENDING_SORT or DESCENDING_SORT macro.\n");
    return 1;
  #endif

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
