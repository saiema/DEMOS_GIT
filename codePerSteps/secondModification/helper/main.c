#include <stdlib.h>
#include <stdio.h>
#include <ordering.h>

void printArray(int values[], int size);

void main(int argc, char ** argv) {
    int values[argc-1];
    for (int i = 0; i < argc - 1; i++) {
        values[i] = atoi(argv[i+1]);
    }
    printf("Original array: ");
    printArray(values, argc-1);
    sort(values, argc-1);
    printf("\nSorted array: ");
    printArray(values, argc-1);
    printf("\n");
}

void printArray(int values[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", values[i]);
        if (i + 1 < size) {
            printf(", ");
        }
    }
    printf("]\n");
}