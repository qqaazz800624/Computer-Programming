#include <stdio.h>
#include <stdlib.h>

int main(){

    int m, n;
    int **scores;
    double school_total = 0.0;
    int total_students = 0;
    int i,j,k;

    if (scanf("%d", &m) != 1){
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (scanf("%d", &n) != 1){
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    scores = (int **)malloc(m * sizeof(int *));
    if (scores == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (i=0; i<m; i++){
        scores[i] = (int *)malloc(sizeof(int) * n);

        if (scores[i] == NULL){
            fprintf(stderr, "Memory allocation failed.\n");
            for (j=0; j<i; j++){
                free(scores[j]);
            }
            free(scores);
            return 1;
        }

        for (j=0; j<n; j++){
            if (scanf("%d", &scores[i][j]) != 1){
                fprintf(stderr, "Error reading score for class %d student %d.\n", i+1, j+1);
                for (k=0; k<=i; k++){
                    free(scores[k]);
                }
                free(scores);
                return 1;
            }
        }
    }

    for (i=0; i<m; i++){
        printf("class %d\n", i+1);
        double class_total = 0.0;
        for (j=0; j<n; j++){
            printf(" %d: %d\n", j+1, scores[i][j]);
            class_total += scores[i][j];
        }
        double class_average = class_total / n;
        printf(" avg: %.2f\n", class_average);

        school_total += class_total;
        total_students += n;
    }

    double school_average = school_total / total_students;
    printf("avg: %.2f\n", school_average);

    for (i=0; i<m; i++){
        free(scores[i]);
    }
    free(scores);

    return 0;
}