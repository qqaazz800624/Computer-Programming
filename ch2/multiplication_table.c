#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    int num_cols;
    int num_rows;
    
    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter the number of columns: ");
    scanf("%d", &num_cols);

    printf("We present a %d * %d multiplication table\n", num_rows, num_cols);
    
    for (row = 1; row < num_rows + 1; row++){
        for (col = 1; col < num_cols + 1; col++){
            printf("%d*%d = %d ", col, row, row*col);
        }
        printf("\n");
    }
    
    return 0;
}