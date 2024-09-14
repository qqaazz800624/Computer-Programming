#include <stdio.h>
#include <stdlib.h>
#define H 3
#define W 4

int main() {
    
    int array[H][W] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int i,j;

    for (i=0; i<H; i++){
        for (j=0; j<W; j++){
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}