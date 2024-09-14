#include <stdio.h>
#include <stdlib.h>
#define CLASS 2
#define STUDENT 3

int main() {
    
    int i, j;
    int scores[CLASS][STUDENT];
    int sum;
    double avg;
    int total;

    // Input scores of students from each class
    for (i=0; i<CLASS; i++){
        for (j=0; j<STUDENT; j++){
            scanf("%d", &scores[i][j]);
        }
    }

    // Output scores of students from each class
    for (i=0; i<CLASS; i++){
        printf("cLass %d:\n", i+1);
        sum = 0;
        for (j=0; j<STUDENT; j++){
            printf(" %d: %d\n", j+1, scores[i][j]);
            sum += scores[i][j];
        }
        avg = (double)sum / STUDENT;
        printf(" sum: %d\n", sum);
        printf(" avg: %.2f\n", avg);
}

    // Total score
    total = 0;
    for (i=0; i<CLASS; i++){
        for (j=0; j<STUDENT; j++){
            total += scores[i][j];
        }
    }   

    // Average score
    avg = (double)total / (CLASS * STUDENT);

    printf("total: %d, avg: %.2f\n", total, avg);
    

    return 0;
}