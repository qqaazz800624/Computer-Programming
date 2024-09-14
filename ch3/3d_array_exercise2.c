#include <stdio.h>
#include <stdlib.h>
#define STUDENT 5
#define SUBJECT 3

int main() {
    
    int i, j;
    int scores[STUDENT][SUBJECT] = {{76, 73, 85}, {88, 84, 76}, {92, 82, 92}, {82, 91, 85}, {72, 74, 73}};
    int sum;
    double avg;
    int MaxScore = 0;
    int MaxIndex = 0;

    for (i=0; i<STUDENT; i++){
        printf("student %d:\n", i+1);
        sum = 0;
        for (j=0; j<SUBJECT; j++){
            sum += scores[i][j];
            printf(" subject %d: %d\n", j+1, scores[i][j]);
        }
        avg = (double)sum/SUBJECT;
        printf(" sum: %d\n", sum);
        printf(" avg: %.2f\n", avg);

        if (sum > MaxScore){
            MaxScore = sum;
            MaxIndex = i;
        }
    }
    printf("The student with the highest average:\n");
    printf(" student %d\n", MaxIndex+1);
    printf(" average: %.2f\n", (double)MaxScore/SUBJECT);
    
    return 0;
}