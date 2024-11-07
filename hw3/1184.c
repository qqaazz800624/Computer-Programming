#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(){

    char filename[128] = {0};
    scanf("%s", filename);

    char output_filename[128];
    strcpy(output_filename, filename);
    output_filename[0] = 'w';

    FILE *input_file;
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    int *numbers;
    numbers = (int *)malloc(MAX_LENGTH * sizeof(int));

    int count = 0, sum = 0;
    int num, i;

    while (fscanf(input_file, "%d", &num) != EOF) {
        numbers[count++] = num;
        sum += num;
    }
    fclose(input_file);

    double average = 0.0;
    if (count > 0) {
        average = (double)sum / count;
    }

    printf("%d\n", sum);
    printf("%.2f\n", average);

    FILE *output_file;
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", output_filename);
        return 1;
    }

    for (i=0; i<count; i++){
        fprintf(output_file, "%d ", numbers[i]);
    }
    fprintf(output_file, "\n");
    fprintf(output_file, "%d\n", sum);
    fprintf(output_file, "%.2f\n", average);
    fclose(output_file);

    free(numbers);

    return 0;
}