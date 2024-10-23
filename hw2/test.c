#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAC_ADDR_LENGTH 18  // 17 characters for MAC address + 1 for null terminator

int main() {
    int n;
    
    // Step 1: Read the number of connected users (n)
    scanf("%d", &n);
    
    // Step 2: Dynamically allocate memory for n MAC addresses
    char **mac_addresses = (char **)malloc(n * sizeof(char *));
    if (mac_addresses == NULL) {
        fprintf(stderr, "Memory allocation failed for mac_addresses.\n");
        return 1;
    }

    // Allocate memory for each MAC address (18 bytes for each string)
    for (int i = 0; i < n; ++i) {
        mac_addresses[i] = (char *)malloc(MAC_ADDR_LENGTH * sizeof(char));
        if (mac_addresses[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for mac_addresses[%d].\n", i);
            return 1;
        }
        // Read the MAC address
        scanf("%s", mac_addresses[i]);
    }

    // Step 3: Read the list of query indices (space-separated values)
    int index;
    while (scanf("%d", &index) != EOF) {
        if (index >= 0 && index < n) {
            printf("%s\n", mac_addresses[index]);  // Print the corresponding MAC address
        } else {
            fprintf(stderr, "Invalid index: %d\n", index);
        }
    }

    // Step 4: Free dynamically allocated memory
    for (int i = 0; i < n; ++i) {
        free(mac_addresses[i]);  // Free each individual MAC address
    }
    free(mac_addresses);  // Free the array of pointers

    return 0;
}
