#include "score.h"
#include <stdio.h>
#include <stdlib.h>


void printAry(int n, int *P){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", P[i]);
    }
    printf("\n");
}

double Avg(int n, int *P){
    int i;
    int sum = 0;
    for(i = 0; i < n; i++){
        sum += P[i];
    }
    return (double)sum / n;
}

int MaxScore(int n, int *P){
    int i;
    int max = P[0];
    int maxIndex = 0;
    for(i = 1; i < n; i++){
        if(P[i] > max){
            max = P[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}