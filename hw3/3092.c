#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char filename[128] = {0}; 
    char name[50];   
    int income = 0, total = 0, count = 0;

    scanf("%s", filename);

    char fileroot[128] = "../app/";
    strcat(fileroot, filename);

    FILE *input;
    input = fopen(fileroot, "r");
    if (input == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    while (fscanf(input, "%s", name) == 1){
        if (fscanf(input, "%d", &income) != 1){
            fprintf(stderr, "Invalid data format.\n");
            fclose(input);
            return 1;
        }

        printf("chef %s %d\n", name, income);

        total += income;
        count++;
    }

    printf("Total: %d\n", total);
    if (count > 0){
        printf("Avg: %.2f\n", (double)total / count);
    } else {
        printf("Avg: 0.00\n");
    }

    fclose(input);

    return 0;
}
