#ifndef MERGESELECTIONSORT_IS_SORTED_H
#define MERGESELECTIONSORT_IS_SORTED_H

int is_sorted(const int *array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return 0;
        }
    }
    return 1;
}

#endif //MERGESELECTIONSORT_IS_SORTED_H
