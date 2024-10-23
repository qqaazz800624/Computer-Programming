#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 10
#define MAX_TRIANGLES 10000  // Define the maximum number of triangles

// Function to compare strings (used in qsort)
int compareNames(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Function to print a list of names with the specified title
void printList(const char *title, char **list, int size) {
    printf("%s: ", title);
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            if (i > 0) printf(",");
            printf("%s", list[i]);
        }
        printf("\n");
    } else {
        printf("None\n");
    }
}

int main() {
    char input[50];
    char name[NAME_LEN];
    int a, b, c;

    // We use fixed arrays for storing the names, assuming a maximum number of triangles
    char notTriangle[MAX_TRIANGLES][NAME_LEN];
    char acuteAngle[MAX_TRIANGLES][NAME_LEN];
    char obtuseAngle[MAX_TRIANGLES][NAME_LEN];
    char rightAngle[MAX_TRIANGLES][NAME_LEN];

    // Pointers to the arrays for sorting
    char *notTrianglePtrs[MAX_TRIANGLES];
    char *acuteAnglePtrs[MAX_TRIANGLES];
    char *obtuseAnglePtrs[MAX_TRIANGLES];
    char *rightAnglePtrs[MAX_TRIANGLES];

    int notTriangleSize = 0, acuteSize = 0, obtuseSize = 0, rightSize = 0;

    // Input reading loop
    while (1) {
        // Read input
        if (!fgets(input, sizeof(input), stdin)) {
            break;  // End of input (in case of unexpected EOF)
        }

        // Check if the input is -1, which means we stop input
        if (strcmp(input, "-1\n") == 0) {
            break;  // End the input when we get "-1"
        }

        // Parsing input into name, a, b, c
        if (sscanf(input, "%s %d %d %d", name, &a, &b, &c) != 4) {
            fprintf(stderr, "Invalid input format. Skipping line.\n");
            continue;  // Skip invalid inputs
        }

        // Safety check: Ensure we don't exceed MAX_TRIANGLES
        if (notTriangleSize >= MAX_TRIANGLES || acuteSize >= MAX_TRIANGLES ||
            obtuseSize >= MAX_TRIANGLES || rightSize >= MAX_TRIANGLES) {
            fprintf(stderr, "Exceeded maximum number of triangles. Stopping input.\n");
            break;
        }

        // Sort a, b, c such that a <= b <= c
        if (a > c) { int temp = a; a = c; c = temp; }
        if (b > c) { int temp = b; b = c; c = temp; }

        // Classify the triangle
        if (a + b <= c) {
            strcpy(notTriangle[notTriangleSize], name);
            notTrianglePtrs[notTriangleSize] = notTriangle[notTriangleSize];
            notTriangleSize++;
        } else if (a * a + b * b > c * c) {
            strcpy(acuteAngle[acuteSize], name);
            acuteAnglePtrs[acuteSize] = acuteAngle[acuteSize];
            acuteSize++;
        } else if (a * a + b * b < c * c) {
            strcpy(obtuseAngle[obtuseSize], name);
            obtuseAnglePtrs[obtuseSize] = obtuseAngle[obtuseSize];
            obtuseSize++;
        } else if (a * a + b * b == c * c) {
            strcpy(rightAngle[rightSize], name);
            rightAnglePtrs[rightSize] = rightAngle[rightSize];
            rightSize++;
        }
    }

    // Sort all lists alphabetically
    if (notTriangleSize > 0) qsort(notTrianglePtrs, notTriangleSize, sizeof(char *), compareNames);
    if (acuteSize > 0) qsort(acuteAnglePtrs, acuteSize, sizeof(char *), compareNames);
    if (obtuseSize > 0) qsort(obtuseAnglePtrs, obtuseSize, sizeof(char *), compareNames);
    if (rightSize > 0) qsort(rightAnglePtrs, rightSize, sizeof(char *), compareNames);

    // Print the lists
    printList("Not Triangle", notTrianglePtrs, notTriangleSize);
    printList("Acute Angle", acuteAnglePtrs, acuteSize);
    printList("Obtuse Angle", obtuseAnglePtrs, obtuseSize);
    printList("Right Angle", rightAnglePtrs, rightSize);

    return 0;
}
