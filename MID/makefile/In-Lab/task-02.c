#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int arr[argc-1];
    int i;

    for (i = 1; i < argc; i++) {
        arr[i-1] = atoi(argv[i]);
    }

    bubbleSort(arr, argc-1);

    printf("Sorted Array: ");
    for (i = 0; i < argc-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
