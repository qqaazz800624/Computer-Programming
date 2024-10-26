#include <stdio.h>
#include <stdlib.h>


int main(){

    int N;
    int *array;
    int i;
    int median;

    scanf("%d", &N);

    array = (int*)malloc(sizeof(int)*N);
    for (i=0; i<N; i++){
        scanf("%d", &array[i]);
    }

    if (N % 2 == 0){
        median = (array[N/2 - 1] + array[N/2] + 1)/2;
        printf("%d\n", median);
    } else {
        median = array[N/2];
        printf("%d\n", median);
    }

    free(array);

    return 0;
}

