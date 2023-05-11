#ifndef _ORDERING
#define _ORDERING

typedef enum Ordering {ASCENDING, DESCENDING} Ordering;

void order(int values[], int size, Ordering ordering);
void orderAscending(int values[], int size);
void orderDescending(int values[], int size);

#endif