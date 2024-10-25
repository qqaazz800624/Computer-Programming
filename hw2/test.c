#include <stdio.h>
#include <stdlib.h>


int main(){

    int N, K;
    int *scores;
    int i;
    int median;

    scanf("%d", &N);
    scanf("%d", &K);

    scores = (int*)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++){
        scanf("%d", &scores[i]);
    }

    if (N % 2 == 0){
        median = scores[N/2 - 1];
        printf("%d\n", median);
        if (K > median){
            printf("WINNER WINNER CHICKEN DINNER!\n");
        }
        else{
            printf("BETTER LUCK NEXT TIME!\n");
        }
    } else {
        median = scores[(N-1)/2];
        printf("%d\n", median);
        if (K > median){
            printf("WINNER WINNER CHICKEN DINNER!\n");
        }
        else{
            printf("BETTER LUCK NEXT TIME!\n");
        }
    }
    free(scores);

    return 0;
}