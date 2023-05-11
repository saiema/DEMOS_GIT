#include <ordering.h>

int minimum(int a, int b);
int maximum(int a, int b);
int bubbleup(int values[], int size);

void orderAscending(int values[], int size) {
    while (bubbleup(values, size));
}

int bubbleup(int values[], int size) {
    int changed = 0;
    if (size < 2) {
        return 0;
    }
    for (int i = 0; i < size - 1; i++) {
        int firstValue = values[i];
        int secondValue = values[i+1];
        int minValue = minimum(firstValue, secondValue);
        int maxValue = maximum(firstValue, secondValue);
        values[i] = minValue;
        values[i+1] = maxValue;
        changed = changed || minValue != firstValue;
    }
    return changed;
}

int minimum(int a, int b) {
    if (a <= b) {
        return a;
    }
    return b;
}

int maximum(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}