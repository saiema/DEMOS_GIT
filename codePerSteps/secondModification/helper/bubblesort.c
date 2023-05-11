#include <ordering.h>

int bubbleup(int values[], int size);
int maximum(int a, int b);
int minimum(int a, int b);

void sort(int values[], int size) {
    if (size > 1) {
        int arrayChanged = 0;
        while (!arrayChanged) {
            arrayChanged = bubbleup(values, size);
        }
    }
}

int bubbleup(int values[], int size) {
    int changed = 0;
    if (size < 2) {
        return 0;
    }
    for (int i = 0; i < size - 1; i++) {
        int firstValue = values[i];
        int secondValue = values[i+1];
        int maxValue = maximum(firstValue, secondValue);
        int minValue = minimum(firstValue, secondValue);
        values[i] = minValue;
        values[i+1] = maxValue;
        changed = changed || (minValue != firstValue);
    }
    return changed;
}

int maximum(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int minimum(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}