#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int n;
    int i, j;

    scanf("%d", &n);

    // Print the star * at the top
    for (i = 0; i < n - 1; i++){
        printf(" "); // Print the space
    }
    printf("*\n"); // Print the top star

    for (i = 0; i < n - 2 ; i++){
        for (j = 0; j < n - i - 2; j++){
            printf(" "); // Print the space
        }
        printf("/"); // Print the left slash

        for (j = 0; j < 2 * i + 1; j++){
            printf("."); // Print the dot
        }
        printf("\\\n"); // Print the right slash
    }

    // Print the bottom line
    printf("/"); // Print the left slash
    for (i = 0; i < 2 * (n - 2) + 1; i++){
        printf("-"); // Print the dash
    }
    printf("\\\n"); // Print the right slash

    return 0;
}