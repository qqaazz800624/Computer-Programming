#include <stdio.h>
#include <string.h>

int main() {
    char S1[1000], S2[100];
    char *pos, *start;
    int index;

    // Input S1 and S2
    fgets(S1, sizeof(S1), stdin);  // Read the main string
    S1[strcspn(S1, "\n")] = '\0';  // Remove the newline character

    fgets(S2, sizeof(S2), stdin);  // Read the search string
    S2[strcspn(S2, "\n")] = '\0';  // Remove the newline character

    // Initialize the search starting point at the beginning of S1
    start = S1;

    // Search for the substring S2 in S1
    while ((pos = strstr(start, S2)) != NULL) {
        index = pos - S1;  // Calculate the index of the found substring

        // Print the index
        printf("%d\t", index);

        // Print the context: two characters before and two after, if available
        if (index >= 2) {
            printf("%c%c+", S1[index-2], S1[index-1]);
        } else if (index == 1) {
            printf(" %c+", S1[index-1]);
        } else {
            printf("  +");
        }

        // Print the found word (S2)
        printf("%s+", S2);

        // Print the two characters after S2
        if (index + strlen(S2) + 1 < strlen(S1)) {
            printf("%c%c\n", S1[index + strlen(S2)], S1[index + strlen(S2) + 1]);
        } else if (index + strlen(S2) < strlen(S1)) {
            printf("%c \n", S1[index + strlen(S2)]);
        } else {
            printf("  \n");
        }

        // Move the starting point forward to continue searching
        start = pos + 1;
    }

    return 0;
}
