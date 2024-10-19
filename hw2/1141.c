#include <stdio.h>
#include <stdlib.h>

int main(){

    int N;
    int *array;
    int i;
    int total = 0;
    double average = 0.0;
    int count = 0;

    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "Error reading the array size.\n");
        return 1;
    }

    array = (int *)malloc(sizeof(int) * N);
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Error reading element %d.\n", i + 1);
            free(array);
            return 1;
        }
    }

    for (i = 0; i < N; i++) {
        total += array[i];
    }
    average = (double)total / N;

    for (i = 0; i < N; i++) {
        if (array[i] > average) {
            count++;
        }
    }
    printf("%d\n", count);

    free(array);

    return 0;
}