#include <ordering.h>

int bubbleup(int values[], int size, Ordering ordering);

void order(int values[], int size, Ordering ordering) {
    if (size > 1) {
        int arrayChanged = 0;
        while (!arrayChanged) {
            arrayChanged = bubbleup(values, size, ordering);
        }
    }
}

void orderAscending(int values[], int size) {
    order(values, size, ASCENDING);
}

void orderDescending(int values[], int size){
    order(values, size, DESCENDING);
}

int bubbleup(int values[], int size, Ordering ordering) {
    int changed = 0;
    if (size < 2) {
        return 0;
    }
    for (int i = 0; i < size - 1; i++) {
        int firstValue = values[i];
        int secondValue = values[i+1];
        if (ordering == ASCENDING && firstValue > secondValue) {
            values[i] = secondValue;
            values[i+1] = firstValue;
            changed = 1;
        } else if (ordering == DESCENDING && firstValue < secondValue) {
            values[i] = secondValue;
            values[i+1] = firstValue;
            changed = 1;
        }
    }
    return changed;
}