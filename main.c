#include <array.h>
#include <sys/times.h>
#include <time.h>
#include <merge_sort.h>
#include <selection_sort.h>

int main() {

    for (int input_num = 0; input_num < 3; ++input_num) {
        char *opening_filename = malloc(sizeof(char) * 128);

        sprintf(opening_filename, "../input/input%d.txt", input_num + 1);
        FILE *input_file = fopen(opening_filename, "r");

        sprintf(opening_filename, "../output/output%d.csv", input_num + 1);
        FILE *output_file = fopen(opening_filename, "w");

        free(opening_filename);
        opening_filename = NULL;

        fputs("size:merge_sort:selection_sort\n", output_file);

        Array *array = get_array_from_file(input_file);
        while (array != NULL) {
            int *array_for_sort = malloc(array->size);
            for (int i = 0; i < array->size; ++i) {
                array_for_sort[i] = array->arr[i];
            }

            clock_t start_time = clock();
            merge_sort(array_for_sort, array->size);
            clock_t end_merge_sort_time = clock() - start_time;

            for (int i = 0; i < array->size; ++i) {
                array_for_sort[i] = array->arr[i];
            }

            start_time = clock();
            selection_sort(array_for_sort, array->size);
            clock_t end_selection_sort_time = clock() - start_time;

            fprintf(output_file, "%d:", array->size);
            fprintf(output_file, "%f:", (double) end_merge_sort_time / CLOCKS_PER_SEC);
            fprintf(output_file, "%f\n", (double) end_selection_sort_time / CLOCKS_PER_SEC);

            free(array->arr);
            free(array);
            free(array_for_sort);
            array = get_array_from_file(input_file);
        }
        fclose(output_file);
        fclose(input_file);
    }

    return 0;
}
