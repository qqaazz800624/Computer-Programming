#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LEN 50
#define TRIANGLE_NAME_LEN 10
#define INITIAL_CAPACITY 100

int compareNames(const void *a, const void *b);
void printList(const char *title, char **list, int size);

int main() {
    char input[INPUT_LEN];
    char name[TRIANGLE_NAME_LEN];
    int a, b, c;
    int i;

    // Initialize dynamic lists and sizes for each triangle category
    char **notTriangle;
    char **acuteAngle;
    char **obtuseAngle;
    char **rightAngle;

    int notTriangleSize = 0, acuteAngleSize = 0, obtuseAngleSize = 0, rightAngleSize = 0;
    int notTriangleCapacity = INITIAL_CAPACITY, acuteAngleCapacity = INITIAL_CAPACITY;
    int obtuseAngleCapacity = INITIAL_CAPACITY, rightAngleCapacity = INITIAL_CAPACITY;

    notTriangle = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    acuteAngle = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    obtuseAngle = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    rightAngle = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));

    for (i = 0; i < INITIAL_CAPACITY; i++) {
        notTriangle[i] = (char *)malloc(TRIANGLE_NAME_LEN * sizeof(char));
        acuteAngle[i] = (char *)malloc(TRIANGLE_NAME_LEN * sizeof(char));
        obtuseAngle[i] = (char *)malloc(TRIANGLE_NAME_LEN * sizeof(char));
        rightAngle[i] = (char *)malloc(TRIANGLE_NAME_LEN * sizeof(char));
    }

    if (!notTriangle || !acuteAngle || !obtuseAngle || !rightAngle) {
        fprintf(stderr, "Initial memory allocation failed.\n");
        exit(1);
    }

    // Input processing
    while (fgets(input, INPUT_LEN, stdin)) {
        if (strcmp(input, "-1\n") == 0) break;

        if (sscanf(input, "%s %d %d %d", name, &a, &b, &c) != 4) {
            fprintf(stderr, "Invalid input format. Skipping line.\n");
            continue;
        }

        // Sort the sides such that a <= b <= c
        if (a > c) { 
            int temp = a; a = c; c = temp; 
            }
        if (b > c) { 
            int temp = b; b = c; c = temp; 
            }

        // Classify triangle based on side lengths
        if (a + b <= c) {
            strcpy(notTriangle[notTriangleSize], name);
            notTriangleSize++;
        } else if (a * a + b * b < c * c) {
            strcpy(obtuseAngle[obtuseAngleSize], name);
            obtuseAngleSize++;
        } else if (a * a + b * b > c * c) {
            strcpy(acuteAngle[acuteAngleSize], name);
            acuteAngleSize++;
        } else {
            strcpy(rightAngle[rightAngleSize], name);
            rightAngleSize++;
        }
    }

    // Sort each list alphabetically
    if (notTriangleSize > 0) qsort(notTriangle, notTriangleSize, sizeof(char *), compareNames);
    if (acuteAngleSize > 0) qsort(acuteAngle, acuteAngleSize, sizeof(char *), compareNames);
    if (obtuseAngleSize > 0) qsort(obtuseAngle, obtuseAngleSize, sizeof(char *), compareNames);
    if (rightAngleSize > 0) qsort(rightAngle, rightAngleSize, sizeof(char *), compareNames);

    // Print each list with title
    printList("Not Triangle", notTriangle, notTriangleSize);
    printList("Acute Angle", acuteAngle, acuteAngleSize);
    printList("Obtuse Angle", obtuseAngle, obtuseAngleSize);
    printList("Right Angle", rightAngle, rightAngleSize);

    // Free memory for each category list
    for (int i = 0; i < notTriangleSize; i++) {
        free(notTriangle[i]);
    }
    for (int i = 0; i < acuteAngleSize; i++) {
        free(acuteAngle[i]);
    }
    for (int i = 0; i < obtuseAngleSize; i++) {
        free(obtuseAngle[i]);
    }
    for (int i = 0; i < rightAngleSize; i++) {
        free(rightAngle[i]);
    }
    free(notTriangle);
    free(acuteAngle);
    free(obtuseAngle);
    free(rightAngle);

    return 0;
}

int compareNames(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

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
