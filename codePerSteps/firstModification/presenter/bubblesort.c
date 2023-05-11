#include <ordering.h>

int bubbleup(int values[], int size);

void order(int values[], int size) {
    if (size > 1) {
        int arrayChanged = 0;
        while (!arrayChanged) {
            arrayChanged = bubbleup(values, size);
        }
    }
}

int bubbleup(int values[], int size) {
    //TODO: implement
}