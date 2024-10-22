#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* read_input_dynamic();
char* decipher(char *str);

int main(){

    char **input_list = NULL;
    size_t input_count = 0;
    size_t input_capacity = 20;
    size_t i;

    input_list = (char **)malloc(input_capacity * sizeof(char *));
    if (!input_list){
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

        if (input_count >= input_capacity){
            input_capacity *= 2;
            input_list = (char **)realloc(input_list, input_capacity * sizeof(char *));
            if (!input_list){
                fprintf(stderr, "Memory reallocation failed for input list.\n");
                return 1;
            }
        }
        input_list[input_count++] = input;

    }

    for (i=0; i<input_count; ++i){
        char *deciphered_message = NULL;
        deciphered_message = decipher(input_list[i]);
        if (!deciphered_message){
            fprintf(stderr, "Error deciphering message.\n");
            return 1;
        }

        if (i > 0){
            printf(" ");
        }
        printf("%s", deciphered_message);

        free(deciphered_message);
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
    size_t position = 0;
    char *buffer = NULL;

    buffer = (char *)malloc(buffer_size * sizeof(char));

    if (!buffer) {
        fprintf(stderr, "Memory allocation failed for input buffer.\n");
        return NULL;
    }

    int ch;

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
    size_t length = strlen(str);
    char *result = NULL;
    size_t i;

    result = (char *)malloc((length + 1)*sizeof(char));

    if (!result){
        fprintf(stderr, "Memory allocation failed for decipher buffer.\n");
        return NULL;
    }

    for (i=0; i<length; ++i){
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
    result[length] = '\0';
    return result;
}