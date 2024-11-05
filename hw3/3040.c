#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void YEAR(int n, char **lst);

int main() {
    char input[5];
    int count = 0;
    int capacity = 10;

    char **years = (char **)malloc(capacity * sizeof(char *));
    if (years == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    while (1) {
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        if (count >= capacity) {
            capacity *= 2;
            years = (char **)realloc(years, capacity * sizeof(char *));
            if (years == NULL) {
                fprintf(stderr, "Memory reallocation failed.\n");
                return 1;
            }
        }

        years[count] = (char *)malloc((strlen(input) + 1) * sizeof(char));
        if (years[count] == NULL) {
            fprintf(stderr, "Memory allocation failed for year.\n");
            return 1;
        }
        strcpy(years[count], input);
        count++;
    }

    YEAR(count, years);

    for (int i = 0; i < count; i++) {
        free(years[i]);
    }
    free(years);

    return 0;
}

void YEAR(int n, char **lst) {
    char *heavenly_stems[] = {"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"};
    char *earthly_branches[] = {"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"};

    for (int i = 0; i < n; i++) {
        int year = atoi(lst[i]);

        int heavenly_position = (year - 3) % 10;
        heavenly_position = heavenly_position - 1;
        if (heavenly_position < 0) {
            heavenly_position += 10;
            }

        int earthly_position = (year - 3) % 12;
        earthly_position = earthly_position - 1;
        if (earthly_position < 0) {
            earthly_position += 12;
            }

        printf("%d = %s%s年\n", year, heavenly_stems[heavenly_position], earthly_branches[earthly_position]);
    }
}
