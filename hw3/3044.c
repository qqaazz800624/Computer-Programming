#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define REQUIRED_CREDITS 72
#define ELECTIVE_CREDITS 28

int is_passing_grade(const char *grade);

int main(){

    char filename[128] = {0};
    int required_credits = 0, elective_credits = 0;

    scanf("%s", filename);

    FILE *input;
    input = fopen(filename, "r");
    if (input == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    char *line;
    line = (char *)malloc(MAX_LINE_LEN * sizeof(char));

    fgets(line, MAX_LINE_LEN, input); // skip the first line (header)

    while (fgets(line, MAX_LINE_LEN, input)){
        char *course_name, *category, *credits_str, *grade;
        int credits = 0;

        line[strcspn(line, "\r\n")] = '\0';
        course_name = strtok(line, ",");
        category = strtok(NULL, ",");
        credits_str = strtok(NULL, ",");
        grade = strtok(NULL, ",");

        credits = atoi(credits_str);

        if (is_passing_grade(grade)){
            if (strcmp(category, "R") == 0){
                required_credits += credits;
            } else if (strcmp(category, "E") == 0){
                elective_credits += credits;
            }
        }
    }

    fclose(input);

    printf("Required: %d\n", required_credits);
    printf("Elective: %d\n", elective_credits);

    int required_diff = REQUIRED_CREDITS - required_credits;
    int elective_diff = ELECTIVE_CREDITS - elective_credits;

    if (required_diff <= 0 && elective_diff <= 0){
        printf("Y\n");
    } else {
        printf("N\n");
        if (required_diff > 0 && elective_diff > 0){
            printf("Student still needs to complete %d required credits & %d elective credits for graduation.\n", required_diff, elective_diff);
        } else if (required_diff > 0){
            printf("Student still needs to complete %d required credits for graduation.\n", required_diff);
        } else if (elective_diff > 0){
            printf("Student still needs to complete %d elective credits for graduation.\n", elective_diff);
        }
    }

    free(line);

    return 0;
}

int is_passing_grade(const char *grade){
    return strcmp(grade, "F") != 0;
}