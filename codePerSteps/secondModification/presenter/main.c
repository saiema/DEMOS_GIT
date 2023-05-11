#include <stdlib.h>
#include <stdio.h>
#include <ordering.h>

void main(int argc, char ** argv) {
    int size = argc-1;
    int values[size];
    for (int i = 0; i < size; i++) {
        values[i] = atoi(argv[i+1]);
    }
    orderAscending(values, size);
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", values[i]);
        if (i + 1 < size) {
            printf(", ");
        }
    }
    printf("]\n");
}