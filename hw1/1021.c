#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    int num_rows, spaces;
    
    scanf("%d", &num_rows);

    // Descending triangle with spaces
    for (row = 0; row < num_rows; row++){
        for (spaces = 0; spaces < row; spaces++){
            printf("  "); // Two spaces to align with the width of a "* "
        }
        for (col = 0; col < num_rows - row; col++){
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}