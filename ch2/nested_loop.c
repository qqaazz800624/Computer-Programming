#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    int num_stars_each_row;
    int num_rows;
    
    printf("Enter the number of stars each row: ");
    scanf("%d", &num_stars_each_row);
    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);

    for (row = 0; row < num_rows; row++){
        for (col = 0; col < num_stars_each_row; col++){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}