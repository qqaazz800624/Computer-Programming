#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRINGS 100   // Maximum number of strings
#define MAX_LENGTH 128    // Maximum length of each string

int compare_strings(const void *a, const void *b);

int main() {
    int N;
    char input_line[MAX_STRINGS * MAX_LENGTH];
    char *strings[MAX_STRINGS];
    int count = 0;

    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "Error reading the number of strings.\n");
        return 1;
    }

    getchar();

    if (fgets(input_line, sizeof(input_line), stdin) == NULL) {
        fprintf(stderr, "Error reading the line of strings.\n");
        return 1;
    }

    input_line[strcspn(input_line, "\n")] = '\0';

    char *token = strtok(input_line, " ");
    while (token != NULL && count < N) {
        strings[count] = strdup(token);
        if (strings[count] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }
        count++;
        token = strtok(NULL, " ");
    }

    if (count != N) {
        fprintf(stderr, "Number of strings read (%d) does not match N (%d).\n", count, N);
        return 1;
    }

    qsort(strings, N, sizeof(char *), compare_strings);

    for (int i = 0; i < N; i++) {
        printf("%s ", strings[i]);
        free(strings[i]);  
    }
    printf("\n");

    return 0;
}

int compare_strings(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2);
}