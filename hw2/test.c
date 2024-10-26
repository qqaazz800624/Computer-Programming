#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 10000  // Max length of the input string
#define MAX_WORDS 2000   // Max number of words

int is_word_exist(char *word, char *word_list[], int count);
int compare_words(const void *a, const void *b);

int main(){

    char *line1;
    char *line2;
    int i;

    line1 = (char *)malloc(sizeof(char)*MAX_INPUT_LENGTH);
    line2 = (char *)malloc(sizeof(char)*MAX_INPUT_LENGTH);

    if (line1 == NULL || line2 == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    if (fgets(line1, MAX_INPUT_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        free(line1);
        free(line2);
        return 1;
    }
    line1[strcspn(line1, "\n")] = '\0';  // remove the newline character

    if (fgets(line2, MAX_INPUT_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        free(line1);
        free(line2);
        return 1;
    }
    line2[strcspn(line2, "\n")] = '\0';  // remove the newline character

    char **words;
    words = (char **)malloc(sizeof(char *)*MAX_WORDS);
    if (words == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        free(line1);
        free(line2);
        return 1;
    }


    int word_count = 0;

    char *token;
    token = strtok(line1, ";");
    while (token != NULL){
        if (is_word_exist(token, words, word_count) == 0){
            words[word_count] = strdup(token);
            word_count++;
        }
        token = strtok(NULL, ";");
    }

    token = strtok(line2, ",");
    while (token != NULL){
        if (is_word_exist(token, words, word_count) == 0){
            words[word_count] = strdup(token);
            word_count++;
        }
        token = strtok(NULL, ",");
    }

    qsort(words, word_count, sizeof(char *), compare_words);

    for (i=0; i<word_count; i++){
        printf("%s", words[i]);
        if (i != word_count - 1){
            printf(" ");
        }
        free(words[i]);
    }
    printf("\n");

    free(line1);
    free(line2);
    free(words);

    return 0;
}

int is_word_exist(char *word, char *word_list[], int count){
    int i;
    for (i=0; i<count; i++){
        if (strcmp(word, word_list[i]) == 0){
            return 1;
        }
    }
    return 0;
}

// compare words alphabetically
int compare_words(const void *a, const void *b){
    const char *word_a = *(const char **)a;
    const char *word_b = *(const char **)b;
    return strcmp(word_a, word_b);
}