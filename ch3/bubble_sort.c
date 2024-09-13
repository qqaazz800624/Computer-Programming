#include <stdio.h>
#include <stdlib.h>
#define N 5

int main() {
    
    int array[N] = {0};
    int i,j;
    int temp;

    for (i=0; i<N; i++){
        scanf("%d", &array[i]);
    }

    for (j = N; j > 1; j--){
        for (i = 0; i < j-1; i++){
            if (array[i] > array[i+1]){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
    

    for (i=0; i<N; i++){
        printf("%d ", array[i]);
    }

    return 0;
}