#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 100
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int english_score;
    int math_score;
} Student;

void read_scores(const char *filename, Student students[], int *student_count, int is_math);
void write_scores(const char *filename, Student students[], int student_count);
void print_scores(Student students[], int student_count);


int main() {
    Student students[MAX_STUDENTS];
    int student_count = 0;

    read_scores("./english_list.csv", students, &student_count, 0);
    read_scores("./math_list.csv", students, &student_count, 1);

    write_scores("./Score.csv", students, student_count);
    print_scores(students, student_count);

    return 0;
}

void read_scores(const char *filename, Student students[], int *student_count, int is_math) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file);  // skip the first line
    while (fgets(line, sizeof(line), file) != NULL) {
        Student s;
        char *token = strtok(line, ",");
        if (token != NULL) {
            strcpy(s.name, token);  
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            int score = atoi(token);
            if (is_math) {
                int found = 0;
                for (int i = 0; i < *student_count; i++) {
                    if (strcmp(students[i].name, s.name) == 0) {
                        students[i].math_score = score;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(students[*student_count].name, s.name);
                    students[*student_count].english_score = 0;  
                    students[*student_count].math_score = score;
                    (*student_count)++;
                }
            } else {
                strcpy(students[*student_count].name, s.name);
                students[*student_count].english_score = score;
                students[*student_count].math_score = 0;  
                (*student_count)++;
            }
        }
    }
    fclose(file);
}

void write_scores(const char *filename, Student students[], int student_count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < student_count; i++) {
        int total_score = students[i].english_score + students[i].math_score;
        fprintf(file, "%s,%d,\n", students[i].name, total_score);
    }
    fclose(file);
}

void print_scores(Student students[], int student_count) {
    for (int i = 0; i < student_count; i++) {
        int total_score = students[i].english_score + students[i].math_score;
        printf("%s %d\n", students[i].name, total_score);
    }
}