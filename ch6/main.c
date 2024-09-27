#include <stdio.h>
#include <stdlib.h>
#include "score.h"

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