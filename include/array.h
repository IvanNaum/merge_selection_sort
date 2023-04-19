#ifndef MERGESELECTIONSORT_ARRAY_H
#define MERGESELECTIONSORT_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int size;
    int *arr;
} Array;

struct Array *get_array_from_file(FILE *);

#endif //MERGESELECTIONSORT_ARRAY_H
