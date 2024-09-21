#include <stdio.h>
#include <stdlib.h>


int main(){

    int i,j;
    double sum = 0, aver;
    int **student;
    int m,n;

    printf("Please enter the number of classes: ");
    scanf("%d", &m);
    printf("Please enter the number of students in each class: ");
    scanf("%d", &n);

    // Dynamically allocate memory for m classes and n students
    student = (int **)malloc(sizeof(int *) * m);
    for (j=0; j<m; j++){
        student[j] = (int *)malloc(sizeof(int) * n);
    }

    // Input the scores of n students in m classes
    for (j=0; j<m; j++){
        printf("Class %d: \n", j+1);
        for (i=0; i<n; i++){
            printf("student %d: ", i+1);
            scanf("%d", &student[j][i]);
        }
    }

    // Calculate the total sum
    for (j=0; j<m; j++){
        for (i=0; i<n; i++){
            sum += student[j][i];
        }
    }

    // Calculate the average
    aver = sum/(m*n);
    printf("The average is: %lf\n", aver);

    // Free the memory
    for (j=0; j<m; j++){
        free(student[j]);
    }
    free(student);

    return 0;
}