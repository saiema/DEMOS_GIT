#ifndef _ORDERING
#define _ORDERING

typedef enum Ordering {ascending, descending} Ordering;

void orderAscending(int values[], int size);
void orderDescending(int values[], int size);
void order(int values[], int size, Ordering order);

#endif