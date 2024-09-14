#include <stdio.h>
#include <stdlib.h>
#define CLASS 2
#define STUDENT 3
#define SUBJECT 2

int main() {
    
    int i, j, k;
    int scores[CLASS][STUDENT][SUBJECT] = {1,2,3,4,5,6,7,8,9,10,11,12};
    
    for (i=0; i<CLASS; i++){
        printf("class %d:\n", i+1);
        
        for (j=0; j<STUDENT; j++){
            printf(" student %d:\n", j+1);
            for (k=0; k<SUBJECT; k++){
                printf("  subject %d: ", k+1);
                printf("%d\n", scores[i][j][k]);
            }
            
        }
        
    }

    return 0;
}