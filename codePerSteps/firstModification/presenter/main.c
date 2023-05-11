#include <stdlib.h>
#include <stdio.h>
#include <ordering.h>

void main(int argc, char ** argv) {
    int values[argc-1];
    for (int i = 0; i < argc - 1; i++) {
        values[i] = atoi(argv[i+1]);
    }
    order(values, argc-1);
    printf("[");
    for (int i = 0; i < argc - 1; i++) {
        printf("%d", values[i]);
        if (i + 1 < argc - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}