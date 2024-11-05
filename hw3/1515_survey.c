#include "survey.h"
#include <stdio.h>
#include <stdlib.h>

void print_avg(char s[]){
    char filename[128];
    sprintf(filename, "%s", s);
    FILE* fp;

    int score = 0, sum = 0, count = 0;
    double average = 0.0;

    fp = fopen(filename, "r");
    if(fp==NULL){
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    while(fscanf(fp, "%d", &score) != EOF){
        sum+=score;
        count++;
    }

    fclose(fp);

    if (count > 0) {
        average = (double)sum / count;
        printf("%.2f", average);
    } else {
        printf("No scores to calculate average.\n");
    }
}