#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0, j = 0;
    int duplicate_Count = 0;

    int arr[] = {2, 5, 0, 2, 0, 3, 3, 1, 5};
    int length = sizeof(arr)/sizeof(arr[0]);

    for (i = 0; i < length; i++){
        for(j = i+1; j < length; j++){
            if(arr[i] == arr[j]){
                duplicate_Count++;
                break;
            }
        }
    }

    //print the total number of duplicate elements in an array

    printf("a total number of duplicate elements in an array = %u", duplicate_Count);
}
