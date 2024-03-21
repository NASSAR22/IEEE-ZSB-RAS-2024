#include <stdio.h>

void Unique_Elements(int arr[], int size) {
    printf("Unique elements in the array: ");


    for (int i = 0; i < size; i++) {
        int Unique = 1;

        // Check if element is unique or not
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                Unique = 0;
                break;
            }
        }

        // Print the unique elements
        if (Unique) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
}

int main() {
    int arr[] = {2, 5, 0, 2, 0, 3, 3, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Unique_Elements(arr, size);

    return 0;
}
