#include <array.h>


struct Array *get_array_from_file(FILE *file) {
    Array *array = malloc(sizeof(Array));
    fscanf(file, "%d", &array->size);
    if (array->size == 0) {
        free(array);
        return NULL;
    }
    array->arr = malloc(array->size * sizeof(int) + 1);
    for (int i = 0; i < array->size; ++i) {
        fscanf(file, "%d", &array->arr[i]);
    }
    array->arr[array->size] = '\0';
    return array;
}

