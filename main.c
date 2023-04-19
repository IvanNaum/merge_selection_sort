#include <array.h>

int main() {
    FILE *input_file = fopen("input1.txt", "r");

    Array *array = get_array_from_file(input_file);
    printf("%d\n", array->size);
    free(array);

    fclose(input_file);


    return 0;
}
