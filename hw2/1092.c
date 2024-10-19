#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main() {
    int N;
    int *array;
    int i;
    
    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "Error reading the array size.\n");
        return 1;
    }

    if (N < 1 || N > 600000) {
        fprintf(stderr, "Invalid array size.\n");
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

    qsort(array, N, sizeof(int), compare);

    for (i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}

int compare(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;

    if (int_a < int_b) 
        {return -1;}
    else if (int_a > int_b) 
        {return 1;}
    else 
        {return 0;}
}
