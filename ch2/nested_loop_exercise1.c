#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    int num_rows, type;
    
    scanf("%d", &num_rows);
    scanf("%d", &type);
    if (type != 1 && type != 2){
        printf("Invalid type of triangle\n");
    }
    else if (type == 1)
    {
        // Ascending triangle
        for (row = 0; row < num_rows; row++){
            for (col = 0; col < row + 1; col++){
                printf("* ");
            }
            printf("\n");
        }
    }
    else if (type == 2)
    {
        // Descending triangle
        // for (row = 0; row < num_rows; row++){
        //     for (col = 0; col < num_rows - row; col++){
        //         printf("* ");
        //     }
        //     printf("\n");
        // }
        for (row = num_rows; row > 0; row--){
            for (col = 0; col < row; col++){
                printf("* ");
            }
            printf("\n");
        }
    }
    
    return 0;
}