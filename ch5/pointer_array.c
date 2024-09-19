#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(){

    int A[10] = {11,22,33,44,55};
    int *P, i;

    P = A;  // or P = &A : Assign the address of the array A to the pointer P
    for (i = 0; i < N; i++){
        printf("A[%d] => %d, %d\n", i, A[i], &A[i]);
    }
    puts("");

    for (i = 0; i < N; i++){
        printf("P[%d] => %d, %d\n", i, P[i], &P[i]);
    }
    puts("");

    for (i = 0; i < N; i++){
        //printf("*(P+%d) => %d, %d\n", i, *(P+i), &*(P+i));  // &*(P+i) = P+i
        //printf("*(P+%d) => %d, %d\n", i, *(P+i), P+i);  // &*(P+i) = P+i
        printf("*(P+%d) => %d, %d\n", i, *P, &*P);
        P++;
    }
    puts("");

    return 0;
}