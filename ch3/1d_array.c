#include <stdio.h>

int main() {
    
    int i;
    int scores[3];

    for (i=0; i<3; i++){
        printf("Enter a score: ");
        scanf("%d", &scores[i]);
        printf("Score %d received.\n", scores[i]);
    }

    return 0;
}