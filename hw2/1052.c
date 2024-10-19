#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int N;
    int *scores;
    int *fail_indices;
    int *fail_scores;
    int fail_count = 0;
    int highest_score = -1;
    int highest_index = -1;
    double average = 0.0;
    int i;

    if (scanf("%d", &N) != 1){
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (N < 3 || N > 600000){
        fprintf(stderr, "Invalid number of students.\n");
        return 1;
    }

    scores = (int *)malloc(sizeof(int) * N);
    if (scores == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    fail_indices = (int *)malloc(sizeof(int) * N);
    fail_scores = (int *)malloc(sizeof(int) * N);
    if (fail_indices == NULL || fail_scores == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        free(scores);
        return 1;
    }

    for (i=0; i<N; i++){
        if (scanf("%d", &scores[i]) != 1){
            fprintf(stderr, "Invalid input\n");
            free(scores);
            free(fail_indices);
            free(fail_scores);
            return 1;
        }

        if (scores[i] < 0 || scores[i] > 50000){
            fprintf(stderr, "Invalid score\n");
            free(scores);
            free(fail_indices);
            free(fail_scores);
            return 1;
        }
    }

    for (i=0; i<N; i++){
        average += (double)scores[i]/N;

        if (scores[i] < 60){
            fail_indices[fail_count] = i + 1;
            fail_scores[fail_count] = scores[i];
            fail_count++;
        }

        if (scores[i] > highest_score){
            highest_score = scores[i];
            highest_index = i + 1;
        }
    }

    printf("avg = %.2f\n", average);

    printf("fail:\n");
    for (i=0; i<fail_count; i++){
        printf("%d: %d\n", fail_indices[i], fail_scores[i]);
    }

    printf("highest:\n");
    printf("%d: %d\n", highest_index, highest_score);

    free(scores);
    free(fail_indices);
    free(fail_scores);
    return 0;
}