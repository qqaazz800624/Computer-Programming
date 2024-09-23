#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n){
    if (n < 2){
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return 0;
        }
    }

    return 1;
}


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