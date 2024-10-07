#include <stdio.h>
#include <stdlib.h>


int main(){

    int ary[100];
    char fname[100];
    int i;
    int n;  // save the number of elements in the array

    scanf("%s", fname);
    FILE *f1 = fopen(fname, "r");

    fscanf(f1, "%d\n", &n);

    for (i=0; i<n; i++){
        fscanf(f1, "%d ", &ary[i]);
    }

    fclose(f1);

    for (i=0; i<n; i++){
        printf("%d ", ary[i]);
    }
    puts("");

    return 0;
};