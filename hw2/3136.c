#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 101

int main(){

    int N;
    char **emp_numbers;
    int M;
    int i,j;

    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "Error reading the number of employees.\n");
        return 1;
    }

    emp_numbers = malloc(N * sizeof(char *));
    if (emp_numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (i=0; i<N; i++){
        char temp[MAX_LENGTH];
        if (scanf("%100s", temp) != 1){
            fprintf(stderr, "Error reading employee number %d.\n", i+1);
            return 1;
        }
        int len = strlen(temp);
        emp_numbers[i] = malloc((len+1) * sizeof(char));
        if (emp_numbers[i] == NULL){
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }
        strcpy(emp_numbers[i], temp);
    }

    if (scanf("%d", &M) != 1) {
        fprintf(stderr, "Error reading the employee index to check.\n");
        return 1;
    }

    if (M < 1 || M > N){
        fprintf(stderr, "Invalid employee index.\n");
        return 1;
    }

    for (i=0; i<N; i++){
        int len = strlen(emp_numbers[i]);
        for (j=0; j< len/2; j++){
            char temp_char = emp_numbers[i][j];
            emp_numbers[i][j] = emp_numbers[i][len-j-1];
            emp_numbers[i][len-j-1] = temp_char;
        }
    }

    for (i=0; i<N; i++){
        printf("%s", emp_numbers[i]);
        if (i != N-1){
            printf(" ");
        }
    }
    printf("\n");

    printf("%s\n", emp_numbers[M-1]);

    for (i=0; i<N; i++){
        free(emp_numbers[i]);
    }
    free(emp_numbers);

    return 0;
}