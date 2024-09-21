#include <stdio.h>

int main()
{
    int n;
    int i, j;
    scanf("%d", &n);

    for (i = 0; i < n + 1; i++){
        for (j = 1; j < i + 1; j++){
            printf("%d", j);
        }
    }
    printf("\n");

    return 0;
}