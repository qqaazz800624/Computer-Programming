#include <stdio.h>

int main()
{
    int i, n;
    int total = 0;
    char plus = '+';
    scanf("%d", &n);
    for (i=1; i<=n; i++){
        total += i;
        printf("%d", i);

        if (i < n){
            printf(" %c ", plus);
            //printf(" + ");
        }
    }

    printf(" = %d\n", total);
    return 0;
}