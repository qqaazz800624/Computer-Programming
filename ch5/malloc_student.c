#include <stdio.h>
#include <stdlib.h>


int main(){

    // step 1: define a pointer
    int *score;

    int students;
    int i;

    printf("How many students? ");
    scanf("%d", &students);

    // step 2: dynamic memory allocation
    score = (int *)malloc(sizeof(int)*students);

    for (i=0; i<students; i++){
        //printf("student %d = ", i);
        scanf("%d", &score[i]);
    }

    for (i=0; i<students; i++){
        printf("The score of student %d = %d\n", i, score[i]);
    }
    puts("");

    // step 3: release memory
    free(score);    

    return 0;
}