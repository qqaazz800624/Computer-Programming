#include <stdio.h>
#include <stdlib.h>

# define N 3
int main(){

    int *a[N];
    int i,j;
    int ct = 10;

    for (i = 0; i < N; i++){
        a[i] = (int *)malloc(sizeof(int)*(i+1));
    }

    for (i=0; i<N; i++){
        for (j=0; j<i+1; j++){
            a[i][j] = ct;
            ct += 10;
        }
    }

    for (i=0; i<N; i++){
        for (j=0; j<i+1; j++){
            printf("%d ", a[i][j]);
        }
        puts("");
    }

    for (i=0; i<N; i++){
        free(a[i]);
        a[i] = NULL;
    }

    return 0;
}

