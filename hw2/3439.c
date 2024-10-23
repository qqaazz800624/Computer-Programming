#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int i, j;
    
    scanf("%d %d", &n, &m);
    
    int **grid;
    grid = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        grid[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    int y = n - 1;
    int x = m - 1;
    int total_height = grid[y][x];  
    
    while (1) {
        int up = -1, left = -1;
        
        if (y > 0 && grid[y-1][x] > grid[y][x]) {
            up = grid[y-1][x];
        }
        
        if (x > 0 && grid[y][x-1] > grid[y][x]) {
            left = grid[y][x-1];
        }
        
        if (up == -1 && left == -1) {
            break;
        } else if (up > left) {
            y--;
            total_height += grid[y][x];
        } else {
            x--;
            total_height += grid[y][x];
        }
    }
    
    printf("%d, %d\n", y, x);  
    printf("%d\n", total_height);  

    for (i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
