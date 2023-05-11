#include <ordering.h>

int bubbleup(int values[], int size);

void order(int values[], int size) {
    //TODO: implement, it should use bubbleup
}

int bubbleup(int values[], int size) {
    int changed = 0;
    if (size < 2) {
        return 0;
    }
    for (int i = 0; i < size - 1; i++) {
        int firstValue = values[i];
        int secondValue = values[i+1];
        if (firstValue > secondValue) {
            values[i] = secondValue;
            values[i+1] = firstValue;
            changed = 1;
        }
    }
    return changed;
}