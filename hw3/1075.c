#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AGES 10000

void merge(int *ages1, int size1, int *ages2, int size2, int *merged);

int main(){

    int i;
    char file1[128], file2[128];
    char path1[150] = "../app/";
    char path2[150] = "../app/";
    FILE *fp1, *fp2;

    scanf("%s", file1);
    scanf("%s", file2);

    strcat(path1, file1);
    strcat(path2, file2);

    fp1 = fopen(path1, "r");
    fp2 = fopen(path2, "r");

    if (!fp1 || !fp2) {
        fprintf(stderr, "Error opening files.\n");
        return 1;
    }

    int *ages1, *ages2;
    int size1 = 0, size2 = 0;

    ages1 = (int *)malloc(MAX_AGES * sizeof(int));
    ages2 = (int *)malloc(MAX_AGES * sizeof(int));

    while (fscanf(fp1, "%d", &ages1[size1]) == 1) {
        size1++;
    }
    fclose(fp1);

    while (fscanf(fp2, "%d", &ages2[size2]) == 1) {
        size2++;
    }
    fclose(fp2);

    int *merged;
    int merged_size = size1 + size2;

    merged = (int *)malloc(merged_size * sizeof(int));

    merge(ages1, size1, ages2, size2, merged);

    for (i = 0; i < merged_size; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    free(ages1);
    free(ages2);
    free(merged);

    return 0;
}

void merge(int *ages1, int size1, int *ages2, int size2, int *merged) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (ages1[i] < ages2[j]) {
            merged[k++] = ages1[i++];
        } else {
            merged[k++] = ages2[j++];
        }
    }

    while (i < size1) {
        merged[k++] = ages1[i++];
    }

    while (j < size2) {
        merged[k++] = ages2[j++];
    }

}