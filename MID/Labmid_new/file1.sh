#!/bin/bash

# Define the filename for the C code
FILENAME="sort_array.c"

# Create the C file and write the code
cat > $FILENAME << EOF
#include <stdio.h>

// Function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\\n");
}

int main(int argc,char *argv) {
    int arr[argc-1];
    
    // Sort the array
    bubbleSort(argv, argc-1);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, argc-1);

    return 0;
}
EOF

./file2.sh 0