#include <stdio.h>
#include <stdlib.h>


int main(){

    int n;
    int *score;
    int i;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    //int A[n];

    score = (int *)malloc(sizeof(int)*n);

    free(score);

    return 0;
}