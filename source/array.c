#include <array.h>


struct Array *get_array_from_file(FILE *file) {
    Array *array = malloc(sizeof(Array));
    fscanf(file, "%d", &array->size);
    array->arr = malloc(array->size * sizeof(int));
    for (int i = 0; i < array->size; ++i) {
        fscanf(file, "%d", &array->arr[i]);
    }
    return array;
}

