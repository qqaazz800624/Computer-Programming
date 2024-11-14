#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 100  

typedef struct {
    int unit_code;
    int count;
} UnitCount;

int find_or_add_unit(UnitCount units[], int *unit_count, int unit_code);
int compare_units(const void *a, const void *b);


int main() {
    char filename[100];
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 1;
    }

    int coupon_counts[4] = {0};  
    UnitCount units[MAX_UNITS];  
    int unit_count = 0;          

    char line[50];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strlen(line) < 9) continue;

        char type = line[0];
        int type_index;
        if (type == 'A') type_index = 0;
        else if (type == 'B') type_index = 1;
        else if (type == 'C') type_index = 2;
        else if (type == 'D') type_index = 3;
        else continue;  

        coupon_counts[type_index]++;

        int unit_code = atoi(&line[strlen(line) - 3]);

        int index = find_or_add_unit(units, &unit_count, unit_code);
        units[index].count++;
    }

    fclose(file);

    qsort(units, unit_count, sizeof(UnitCount), compare_units);

    printf("優惠券A: %d張\n", coupon_counts[0]);
    printf("優惠券B: %d張\n", coupon_counts[1]);
    printf("優惠券C: %d張\n", coupon_counts[2]);
    printf("優惠券D: %d張\n", coupon_counts[3]);

    printf("\n");

    for (int i = 0; i < unit_count; i++) {
        printf("單位%d: %d張\n", units[i].unit_code, units[i].count);
    }

    return 0;
}

int find_or_add_unit(UnitCount units[], int *unit_count, int unit_code) {
    for (int i = 0; i < *unit_count; i++) {
        if (units[i].unit_code == unit_code) {
            return i;  
        }
    }
    units[*unit_count].unit_code = unit_code;
    units[*unit_count].count = 0;
    return (*unit_count)++;
}


int compare_units(const void *a, const void *b) {
    return ((UnitCount *)a)->unit_code - ((UnitCount *)b)->unit_code;
}