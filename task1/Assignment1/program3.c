#include <stdio.h>

int main()
{
    int arr1[100], arr2[100];
    int n, i, j, ctr;

    // Prompt user for input
    printf("Input the number of elements to size the array: ");
    scanf("%d", &n);

    // Input elements for the array
    printf("Input %d elements in the array:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("element - %d: ", i);
        scanf("%d", &arr1[i]);
        arr2[i] = -1;
    }

    // Count the frequency of each element in the array
    for (i = 0; i < n; i++)
    {
        ctr = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr1[i] == arr1[j])
            {
                ctr++;
                arr2[j] = 0;
            }
        }

        // If frequency array value is not 0, set the counter
        if (arr2[i] != 0)
        {
            arr2[i] = ctr;
        }
    }

    // Print the frequency of each element in the array
    printf("\nThe frequency of all elements in the array:\n");
    for (i = 0; i < n; i++)
    {
        if (arr2[i] != 0)
        {
            printf("%d occurs %d time(s)\n", arr1[i], arr2[i]);
        }
    }

    return 0;
}
