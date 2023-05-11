#include <ordering_2.h>

int minimum(int a, int b);
int maximum(int a, int b);
int bubbleup(int values[], int size, Ordering order);

void orderAscending(int values[], int size) {
    order(values, size, ascending);
}

void orderDescending(int values[], int size) {
    order(values, size, descending);
}

void order(int values[], int size, Ordering order) {
    while (bubbleup(values, size, order));
}

int bubbleup(int values[], int size, Ordering order) {
    int changed = 0;
    if (size < 2) {
        return 0;
    }
    for (int i = 0; i < size - 1; i++) {
        int firstValue = values[i];
        int secondValue = values[i+1];
        int minValue = minimum(firstValue, secondValue);
        int maxValue = maximum(firstValue, secondValue);
        values[i] = order==ascending?minValue:maxValue;
        values[i+1] = order==ascending?maxValue:minValue;
        changed = changed || (order==ascending?minValue:maxValue) != firstValue;
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