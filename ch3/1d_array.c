#include <stdio.h>
#include <stdlib.h>
#define N 3

int main() {
    
    int i;
    int scores[N];

    for (i=0; i<N; i++){
        scanf("%d", &scores[i]);
        printf("Score %d received.\n", scores[i]);
    }

    return 0;
}