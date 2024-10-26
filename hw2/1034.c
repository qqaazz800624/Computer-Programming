#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int N = 5;
    int *array;
    int i, j;

    array = (int *)malloc(N * sizeof(int));

    for (i = 0; i < N; i++){
        scanf("%d", &array[i]);
    }

    for (i = 0; i < N; i++){
        printf("%d\t", array[i]);
        for (j = 0; j < array[i]; j++){
            printf("*");
        }
        printf("\n");
    }

    free(array);

    return 0;
}

