#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAC_ADDR_LENGTH 20 // 17 characters + null terminator

int main() {
    int n, i;
    
    // Read the number of connected users
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error reading the number of connected users.\n");
        return 1;
    }
    
    // Consume the newline character after 'n'
    getchar();
    
    // Allocate memory for n MAC addresses
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
    
    size_t buffer_size = 1000000; // Adjust the size if needed
    char *indices_line = (char *)malloc(buffer_size * sizeof(char));
    if (fgets(indices_line, buffer_size, stdin) == NULL) {
        fprintf(stderr, "Error reading indices line.\n");
        free(indices_line);
        return 1;
    }

    
    // Parse indices from the line
    char *token = strtok(indices_line, " \n");
    while (token != NULL) {
        int idx = atoi(token);
        if (idx >= 0 && idx < n) {
            printf("%s\n", mac_addresses[idx]);
        } else {
            fprintf(stderr, "Invalid query index: %d\n", idx);
        }
        token = strtok(NULL, " \n");
    }
    
    // Free allocated memory
    for (i = 0; i < n; ++i) {
        free(mac_addresses[i]);
    }
    free(mac_addresses);
    free(indices_line);
    
    return 0;
}
