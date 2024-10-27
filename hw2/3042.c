#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* read_input_dynamic();
char* decipher(char *str);

int main() {
    
    char **input_list = NULL;
    int input_count = 0;
    size_t INPUT_CAPACITY = 20;
    int i;

    input_list = (char **)malloc(INPUT_CAPACITY * sizeof(char *));
    if (!input_list) {
        fprintf(stderr, "Memory allocation failed for input list.\n");
        return 1;
    }

    while (1){
        char *input = NULL;
        input = read_input_dynamic();

        if (!input){
            fprintf(stderr, "Error reading input.\n");
            return 1;
        }

        if (strcmp(input, "-1") == 0){
            free(input);
            break;
        }

        if (input_count >= INPUT_CAPACITY){
            INPUT_CAPACITY *= 2;
            input_list = (char **)realloc(input_list, INPUT_CAPACITY * sizeof(char *));
            if (!input_list){
                fprintf(stderr, "Memory reallocation failed for input list.\n");
                return 1;
            }
        }
        input_list[input_count++] = input;
    }

    for (i=0; i<input_count; ++i){
        char *decipherd_message = NULL;
        decipherd_message = decipher(input_list[i]);
        if (!decipherd_message){
            fprintf(stderr, "Error deciphering message.\n");
            return 1;
        }
        if (i > 0){
            printf(" ");
        }
        printf("%s", decipherd_message);
        free(decipherd_message);
    }
    printf("\n");

    for (i=0; i<input_count; ++i){
        free(input_list[i]);
    }
    free(input_list);

    return 0;
}

char* read_input_dynamic(){
    size_t buffer_size = 20;
    char *buffer = NULL;
    int ch;
    int position = 0;

    buffer = (char *)malloc(buffer_size * sizeof(char));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed for input buffer.\n");
        return NULL;
    }

    while ((ch = getchar()) != EOF && ch != '\n'){
        buffer[position++] = (char)ch;
        if (position >= buffer_size){
            buffer_size *= 2;
            buffer = (char *)realloc(buffer, buffer_size * sizeof(char));
            if (!buffer){
                fprintf(stderr, "Memory reallocation failed.\n");
                return NULL;
            }
        }
    }
    buffer[position] = '\0';
    return buffer;
}

char* decipher(char *str){
    size_t len = strlen(str);
    char *result = NULL;
    int i;

    result = (char *)malloc((len+1) * sizeof(char));
    if (!result){
        fprintf(stderr, "Memory allocation failed for decipher buffer.\n");
        return NULL;
    }

    for (i=0; i<len; ++i){
        if (isalpha(str[i])){
            char ch = tolower(str[i]);
            if (ch >= 'a' && ch <= 'c'){
                ch = ch + 26 - 3;
            } else {
                ch = ch - 3;
            }
            result[i] = ch;
        } else {
            result[i] = str[i];
        }
    }
    result[len] = '\0';
    return result;
}