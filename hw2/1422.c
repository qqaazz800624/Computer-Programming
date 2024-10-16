#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 200   // Max number of words
#define MAX_LENGTH 1000  // Max length of a word

// Check if a word is in the word list
int is_word_exist(char *word, char *word_list[], int count);

// Compare function for qsort
int compare_words(const void *a, const void *b);


int main() {
    
    char *line1;
    char *line2;

    line1 = (char *)malloc(sizeof(char)*MAX_LENGTH);
    line2 = (char *)malloc(sizeof(char)*MAX_LENGTH);

    if (line1 == NULL || line2 == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read the first line
    if (fgets(line1, MAX_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        free(line1);
        free(line2);
        return 1;
    }
    line1[strcspn(line1, "\n")] = '\0';  // remove the newline character

    // Read the second line
    if (fgets(line2, MAX_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        free(line1);
        free(line2);
        return 1;
    }
    line2[strcspn(line2, "\n")] = '\0';  // remove the newline character

    char *words[MAX_WORDS];
    int word_count = 0;

    char *token = strtok(line1, ";");
    while (token != NULL) {
        if (!is_word_exist(token, words, word_count)) {
            words[word_count] = strdup(token);
            word_count++;
        }
        token = strtok(NULL, ";");
    }

    token = strtok(line2, ",");
    while (token != NULL) {
        if (!is_word_exist(token, words, word_count)) {
            words[word_count] = strdup(token);
            word_count++;
        }
        token = strtok(NULL, ",");
    }

    qsort(words, word_count, sizeof(char *), compare_words);

    for (int i = 0; i < word_count; i++) {
        printf("%s", words[i]);
        if (i != word_count - 1) {
            printf(" ");
        }
        free(words[i]);  
    }
    printf("\n");

    free(line1);
    free(line2);

    return 0;
}

int is_word_exist(char *word, char *word_list[], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(word, word_list[i]) == 0) {
            return 1;  // the word exists
        }
    }
    return 0;  // the word does not exist
}

int compare_words(const void *a, const void *b) {
    const char *word_a = *(const char **)a;
    const char *word_b = *(const char **)b;
    return strcmp(word_a, word_b);
}