#include <stdio.h>
#include <stdlib.h>
#include "score.h"


int main() {
    int student;
    int *score;
    double aver;
    int i;

    scanf("%d", &student);

    score = (int*) malloc(sizeof(int) * student);

    for(i = 0; i < student; i++){
        scanf("%d", &score[i]);
    }

    aver = Avg(student, score);
    printf("avg = %.2lf\n", aver);
    printf("highest:\n");
    int Maxpos=MaxScore(student,score);
    printf("%d: %d\n", Maxpos+1, score[Maxpos]);

    free(score);
}