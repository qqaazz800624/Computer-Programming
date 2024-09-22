#include <stdio.h>
#include <math.h>

int isSevenMultiples(int num){
    return num % 7 == 0;
}

int isSevenDigits(int num){
    int digit;
    while(num != 0){
        digit = num % 10;
        if (digit == 7){
            return 1;
        }
        num /= 10;
    }
    return 0;
}

int main()
{
    int n, m;
    int found = 0;
    int i;

    scanf("%d %d", &n, &m);

    for (i = n; i <= m; i++){
        if (isSevenMultiples(i)){
            if (found){
                printf(" & ");
            }
            printf("%d", i);
            found = 1;
        }
    }
    printf("\n");

    found = 0;
    for (i = n; i <= m; i++){
        if (isSevenDigits(i)){
            if (found){
                printf(" & ");
            }
            printf("%d", i);
            found = 1;
        }
    }

    if (!found){
        printf("none");
    }
    printf("\n");

    return 0;
}