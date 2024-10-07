#include <stdio.h>
#include <stdlib.h>

#define N 5
int main(){

    int ary[N] = {11, 22, 33, 44, 55};
    char fname[100];
    int i;

    scanf("%s", fname);
    FILE *f1 = fopen(fname, "w");

    printf("%d\n", N);
    fprintf(f1, "%d\n", N);

    for (i=0; i<N; i++){
        printf("%d ", ary[i]);
        fprintf(f1, "%d ", ary[i]);
    }

    fclose(f1);

    return 0;
};