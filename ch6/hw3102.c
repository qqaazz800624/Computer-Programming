#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main()
{
    int m;
    int i;
    scanf("%d", &m);

    for (i = 2; i <= m; i++){
        if (isPrime(i)){
            printf("%d is prime\n", i);
        }
    }

    return 0;
}