#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAC_ADDR_LENGTH 20 // 17 characters + null terminator
#define INITIAL_INDICES_CAPACITY 10000 // Initial capacity for indices

// Function to dynamically read indices and store them in an integer array
int* read_indices_dynamic(size_t* count) {
    size_t capacity = INITIAL_INDICES_CAPACITY;
    int* indices = (int*)malloc(capacity * sizeof(int));
    if (!indices) {
        fprintf(stderr, "Memory allocation failed for indices.\n");
        return NULL;
    }

    *count = 0;
    char* line = NULL;
    size_t line_size = 0;

    // Read the entire line of indices
    if (getline(&line, &line_size, stdin) == -1) {
        free(indices);
        free(line);
        return NULL;
    }

    char* token = strtok(line, " \n");
    while (token != NULL) {
        if (*count >= capacity) {
            // Reallocate more space when needed
            capacity *= 2;
            indices = (int*)realloc(indices, capacity * sizeof(int));
            if (!indices) {
                fprintf(stderr, "Memory reallocation failed for indices.\n");
                free(line);
                return NULL;
            }
        }

        // Parse the token as an integer and store it in the array
        indices[*count] = strtol(token, NULL, 10);
        (*count)++;

        token = strtok(NULL, " \n");
    }

    free(line); // Free the line buffer after use
    return indices;
}

int main() {
    int n, i;

    // Read the number of connected users
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error reading the number of connected users.\n");
        return 1;
    }

    // Consume the newline character after 'n'
    getchar();

    // Dynamically allocate memory for n MAC addresses
    char **mac_addresses = (char **)malloc(n * sizeof(char *));
    if (mac_addresses == NULL) {
        fprintf(stderr, "Memory allocation failed for mac_addresses.\n");
        return 1;
    }

    // Read n MAC addresses
    for (i = 0; i < n; ++i) {
        mac_addresses[i] = (char *)malloc(MAC_ADDR_LENGTH);
        if (mac_addresses[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for mac_addresses[%d].\n", i);
            return 1;
        }
        if (fgets(mac_addresses[i], MAC_ADDR_LENGTH, stdin) == NULL) {
            fprintf(stderr, "Error reading MAC address %d.\n", i);
            return 1;
        }
        // Remove newline character if present
        size_t len = strlen(mac_addresses[i]);
        if (len > 0 && mac_addresses[i][len - 1] == '\n') {
            mac_addresses[i][len - 1] = '\0';
        }
    }

    // Dynamically read indices and store them in an array
    size_t indices_count;
    int* indices = read_indices_dynamic(&indices_count);
    if (!indices) {
        fprintf(stderr, "Error reading indices line.\n");
        return 1;
    }

    // Output the MAC addresses corresponding to the indices
    for (i = 0; i < indices_count; ++i) {
        int idx = indices[i];
        if (idx >= 0 && idx < n) {
            printf("%s\n", mac_addresses[idx]);
        } else {
            fprintf(stderr, "Invalid query index: %d\n", idx);
        }
    }

    // Free allocated memory
    for (i = 0; i < n; ++i) {
        free(mac_addresses[i]);
    }
    free(mac_addresses);
    free(indices);

    return 0;
}
