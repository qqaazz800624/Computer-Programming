#include <stdio.h>
#include <stdlib.h>
#define N 3

int main() {
    
    int score[N];
    int sum = 0;
    double avg = 0.0;

    int i;
    for (i=0; i<N; i++){
        scanf("%d", &score[i]);
    }
    printf("\n");

    sum = 0;
    for (i=0; i<N; i++){
        sum += score[i];
    }
 
    avg = (double)sum / N;

    //printf("sum = %d\n", sum);
    printf("avg = %.2f\n", avg);
    printf("fail:\n");

    for (i = 0; i < N; i++){
        if (score[i] < 60){
            printf("%d: %d\n", i+1, score[i]);
        }
    }

    int MaxScore = 0;
    int MaxIndex = 0;

    for (i = 0; i < N; i++){
        if (score[i] > MaxScore){
            MaxScore = score[i];
            MaxIndex = i;
        }
    }
    printf("highest:\n");
    printf("%d: %d\n", MaxIndex+1, MaxScore);

    return 0;
}