#include <stdio.h>
#include <stdlib.h>

void printAry(int n, int *P);
double Avg(int n, int *P);
int MaxScore(int n, int *P);

int main(){
    
    //int score[5] = {11, 22, 33, 44, 55};
    int *score, n;
    int i;

    scanf("%d", &n);
    score = (int *)malloc(sizeof(int)*n);

    for (i = 0; i <n; i++){
        //scanf("%d", &score[i]);
        scanf("%d", score+i);
    }

    printAry(n, score);
    printf("Average = %.2f\n", Avg(n, score));
    printf("%d: %d\n", MaxScore(n, score)+1, score[MaxScore(n, score)]);

    free(score);

    return 0;
}

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