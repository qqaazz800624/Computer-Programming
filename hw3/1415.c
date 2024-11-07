#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1000

int compare(const void *a, const void *b);

int main(){

    char filename[128] = {0};
    scanf("%s", filename);

    FILE *input_file;
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    char input_header[50];
    fgets(input_header, sizeof(input_header), input_file);

    int *retake_ids;
    retake_ids = (int *)malloc(MAX_LENGTH * sizeof(int));

    int retake_count = 0;
    int id, score, i;

    while (fscanf(input_file, "%d,%d", &id, &score) != EOF) {
        double adjusted_score = sqrt(score) * 11;

        if (adjusted_score < 60 && retake_count < MAX_LENGTH) {
            retake_ids[retake_count++] = id;
        }
    }
    fclose(input_file);

    qsort(retake_ids, retake_count, sizeof(int), compare);

    for (i=0; i<retake_count; i++){
        if (i > 0) {
            printf(" ");
        }
        printf("%d", retake_ids[i]);
    }
    printf("\n");

    free(retake_ids);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}