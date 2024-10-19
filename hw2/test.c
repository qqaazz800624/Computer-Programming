#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 101  // Maximum length of employee number plus null terminator

int main() {
    int N;  // Number of employees
    char **employee_numbers;  // Array of pointers to employee numbers
    int M;  // Position of the employee to check

    // Read the number of employees
    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "Error reading the number of employees.\n");
        return 1;
    }

    // Allocate memory for N employee numbers
    employee_numbers = malloc(N * sizeof(char *));
    if (employee_numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read N employee numbers
    for (int i = 0; i < N; i++) {
        char temp[MAX_LENGTH];
        if (scanf("%100s", temp) != 1) {
            fprintf(stderr, "Error reading employee number %d.\n", i + 1);
            return 1;
        }
        int len = strlen(temp);
        // Allocate memory for each employee number
        employee_numbers[i] = malloc((len + 1) * sizeof(char));
        if (employee_numbers[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }
        strcpy(employee_numbers[i], temp);
    }

    // Reverse each employee number
    for (int i = 0; i < N; i++) {
        int len = strlen(employee_numbers[i]);
        for (int j = 0; j < len / 2; j++) {
            char temp_char = employee_numbers[i][j];
            employee_numbers[i][j] = employee_numbers[i][len - j - 1];
            employee_numbers[i][len - j - 1] = temp_char;
        }
    }

    // Print the reversed employee numbers
    for (int i = 0; i < N; i++) {
        printf("%s", employee_numbers[i]);
        if (i != N - 1) {
            printf(" ");
        }
    }
    printf("\n");

    // Read the position of the employee to check
    if (scanf("%d", &M) != 1) {
        fprintf(stderr, "Error reading the employee position.\n");
        return 1;
    }

    // Validate the position
    if (M < 1 || M > N) {
        fprintf(stderr, "Invalid employee position.\n");
        return 1;
    }

    // Output the reversed employee number at position M
    printf("%s\n", employee_numbers[M - 1]);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(employee_numbers[i]);
    }
    free(employee_numbers);

    return 0;
}
