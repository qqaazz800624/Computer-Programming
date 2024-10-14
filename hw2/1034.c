#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int main(){
    int array[N];
    int i,j;
    for(i=0;i<N;i++){
        scanf("%d",&array[i]);
    }
    for(i=0;i<N;i++){
        printf("%d\t",array[i]);
        for(j=0;j<array[i];j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

