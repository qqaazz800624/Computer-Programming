#include "1063_score.h"

double Avg(int n, int *p){
    int i;
    double sum = 0;
    double aver;
    for(i = 0; i < n; i++)
    {
    sum += p[i];
    }
    return (double)sum / n;
}

int MaxScore(int n, int *p){
    int MP=0;
    int i;
    for(i = 0; i < n; i++)
    {
    if(p[i]>p[MP]){
    MP=i;
    }
    }
    return MP;
}