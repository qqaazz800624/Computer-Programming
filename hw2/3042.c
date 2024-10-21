#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


char* read_input_dynamic() {
    size_t buffer_size = 10;  
    size_t position = 0;
    char *buffer = (char *)malloc(buffer_size * sizeof(char));

    if (!buffer) {
        fprintf(stderr, "Memory allocation failed for input buffer.\n");
        return NULL;
    }

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        buffer[position++] = (char)ch;
        
        if (position >= buffer_size) {
            buffer_size *= 2;  
            buffer = (char *)realloc(buffer, buffer_size * sizeof(char));
            if (!buffer) {
                fprintf(stderr, "Memory reallocation failed.\n");
                return NULL;
            }
        }
    }

    buffer[position] = '\0';  
    return buffer;
}


char* decrypt(char *str) {
    size_t length = strlen(str);
    char *result = (char *)malloc((length + 1) * sizeof(char));  

    if (!result) {
        fprintf(stderr, "Memory allocation failed for decryption buffer.\n");
        return NULL;
    }

    for (size_t i = 0; i < length; ++i) {
        if (isalpha(str[i])) {
            char ch = tolower(str[i]);  
            if (ch >= 'a' && ch <= 'c') {
                ch = ch + 26 - 3;  // Handle 'a' to 'c' shifting back to 'x', 'y', 'z'
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

int main() {
    char **input_list = NULL;  
    size_t input_count = 0;
    size_t input_capacity = 10;  

    input_list = (char **)malloc(input_capacity * sizeof(char *));
    if (!input_list) {
        fprintf(stderr, "Memory allocation failed for input list.\n");
        return 1;
    }

    while (1) {
        char *input = read_input_dynamic();

        if (!input) {
            fprintf(stderr, "Error reading input.\n");
            return 1;
        }

        if (strcmp(input, "-1") == 0) {
            free(input);
            break;
        }

        if (input_count >= input_capacity) {
            input_capacity *= 2;  
            input_list = (char **)realloc(input_list, input_capacity * sizeof(char *));
            if (!input_list) {
                fprintf(stderr, "Memory reallocation failed for input list.\n");
                return 1;
            }
        }

        input_list[input_count++] = input;  
    }

    for (size_t i = 0; i < input_count; ++i) {
        char *decrypted_message = decrypt(input_list[i]);
        if (!decrypted_message) {
            fprintf(stderr, "Error decrypting message.\n");
            return 1;
        }

        if (i > 0) {
            printf(" ");
        }

        printf("%s", decrypted_message);
        free(decrypted_message);  
    }

    printf("\n");

    
    for (size_t i = 0; i < input_count; ++i) {
        free(input_list[i]);
    }
    free(input_list);  

    return 0;
}
