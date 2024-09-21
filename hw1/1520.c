#include <stdio.h>

int main()
{
    int a;
    char b;
    int i;
    scanf("%d %c", &a, &b);
    
    while (1) {
        if (a < 0){
            break;
        }
        else if (a >= 0 && a <= 10){
            for (i = 0; i < a; i++){
                printf("%c ", b);
            }
            printf("\n");
            break;
        }
        a -= 10;
    }

    return 0;
}