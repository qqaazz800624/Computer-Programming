#include <stdio.h>
#include <stdlib.h>

int main(){

    char filename[128];
    FILE *infile;
    int score = 0, sum = 0, count = 0;
    double average = 0.0;

    scanf("%s", filename);
    infile = fopen(filename, "r");
    if (infile == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return 1;
    }

    while (fscanf(infile, "%d", &score) != EOF) {
        sum += score;
        count++;
    }

    fclose(infile);

    if (count > 0) {
        average = (double)sum / count;
        printf("%.2f", average);
    } else {
        printf("No scores to calculate average.\n");
    }

    return 0;
}