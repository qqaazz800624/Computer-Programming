#include <stdio.h>
#include <stdlib.h>
#define CLASS 2
#define STUDENT 3

int main() {
    
    int i, j;
    int scores[CLASS][STUDENT];
    int sum;
    double avg;

    // Input scores of students from each class
    for (i=0; i<CLASS; i++){
        printf("CLass %d:\n", i+1);
        for (j=0; j<STUDENT; j++){
            printf(" Student %d: ", j+1);
            scanf("%d", &scores[i][j]);
        }
    }

    // Output scores of students from each class
    for (i=0; i<CLASS; i++){
        printf("CLass %d:\n", i+1);
        for (j=0; j<STUDENT; j++){
            printf(" Student %d: %d分\n", j+1, scores[i][j]);
        }
    }

    // Total score
    sum = 0;
    for (i=0; i<CLASS; i++){
        for (j=0; j<STUDENT; j++){
            sum += scores[i][j];
        }
    }   

    // Average score
    avg = (double)sum / (CLASS * STUDENT);

    printf("Total score: %d\n", sum);
    printf("Average score: %.2f\n", avg);

    return 0;
}