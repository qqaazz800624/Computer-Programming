#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAC_ADDR_LENGTH 18  

int main() {
    int n;
    
    scanf("%d", &n);
    
    char **mac_addresses = (char **)malloc(n * sizeof(char *));
    if (mac_addresses == NULL) {
        fprintf(stderr, "Memory allocation failed for mac_addresses.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        mac_addresses[i] = (char *)malloc(MAC_ADDR_LENGTH * sizeof(char));
        if (mac_addresses[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for mac_addresses[%d].\n", i);
            return 1;
        }
        scanf("%s", mac_addresses[i]);
    }

    int index;
    while (scanf("%d", &index) != EOF) {
        if (index >= 0 && index < n) {
            printf("%s\n", mac_addresses[index]);  
        } else {
            fprintf(stderr, "Invalid index: %d\n", index);
        }
    }

    for (int i = 0; i < n; ++i) {
        free(mac_addresses[i]);  
    }
    free(mac_addresses);  

    return 0;
}
