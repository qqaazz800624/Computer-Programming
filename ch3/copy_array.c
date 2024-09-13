#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

int main() {
    
    int i;
    int array1[N] = {11, 22, 33, 44, 55};
    int array2[N] = {0};

    // Cannot use array2 = array1;
    memcpy(array2, array1, sizeof(int)*N);

    for (i=0; i<N; i++){
        printf("array1[%d] = %d\n", i, array1[i]);
    }
    printf("\n");

    for (i=0; i<N; i++){
        printf("array2[%d] = %d\n", i, array2[i]);
    }
    printf("\n");

    return 0;
}