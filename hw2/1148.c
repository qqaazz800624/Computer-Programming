#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    int sides[3];
} Triangle;

int compareNames(const void *a, const void *b) {
    return strcmp(((Triangle *)a)->name, ((Triangle *)b)->name);
}

int main() {
    Triangle triangles[100];
    int triangleCount = 0;

    // Input reading
    while (1) {
        char input[50];
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "-1\n") == 0) {
            break;
        }

        sscanf(input, "%s %d %d %d",
               triangles[triangleCount].name,
               &triangles[triangleCount].sides[0],
               &triangles[triangleCount].sides[1],
               &triangles[triangleCount].sides[2]);

        triangleCount++;
    }

    // Sort triangles by name
    qsort(triangles, triangleCount, sizeof(Triangle), compareNames);

    char notTriangle[1000] = "";
    char acuteAngle[1000] = "";
    char obtuseAngle[1000] = "";
    char rightAngle[1000] = "";

    // Classify triangles
    for (int i = 0; i < triangleCount; i++) {
        int a = triangles[i].sides[0];
        int b = triangles[i].sides[1];
        int c = triangles[i].sides[2];

        // Sort a, b, c to make sure a <= b <= c
        if (a > b) { int temp = a; a = b; b = temp; }
        if (b > c) { int temp = b; b = c; c = temp; }
        if (a > b) { int temp = a; a = b; b = temp; }

        if (a + b <= c) {
            // Not a triangle
            strcat(notTriangle, triangles[i].name);
            strcat(notTriangle, ",");
        } else {
            int a2b2 = a * a + b * b;
            int c2 = c * c;

            if (a2b2 > c2) {
                strcat(acuteAngle, triangles[i].name);
                strcat(acuteAngle, ",");
            } else if (a2b2 < c2) {
                strcat(obtuseAngle, triangles[i].name);
                strcat(obtuseAngle, ",");
            } else {
                strcat(rightAngle, triangles[i].name);
                strcat(rightAngle, ",");
            }
        }
    }

    // Print results
    if (strlen(notTriangle) > 0) {
        notTriangle[strlen(notTriangle) - 1] = '\0';
        printf("Not Triangle: %s\n", notTriangle);
    } else {
        printf("Not Triangle: None\n");
    }

    if (strlen(acuteAngle) > 0) {
        acuteAngle[strlen(acuteAngle) - 1] = '\0';
        printf("Acute Angle: %s\n", acuteAngle);
    } else {
        printf("Acute Angle: None\n");
    }

    if (strlen(obtuseAngle) > 0) {
        obtuseAngle[strlen(obtuseAngle) - 1] = '\0';
        printf("Obtuse Angle: %s\n", obtuseAngle);
    } else {
        printf("Obtuse Angle: None\n");
    }

    if (strlen(rightAngle) > 0) {
        rightAngle[strlen(rightAngle) - 1] = '\0';
        printf("Right Angle: %s\n", rightAngle);
    } else {
        printf("Right Angle: None\n");
    }

    return 0;
}
