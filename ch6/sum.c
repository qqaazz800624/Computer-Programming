#include <stdio.h>
#include <stdlib.h>

int sum(int n);

int main(){
    
    int x;
    scanf("%d", &x);

    printf("Sum of 1 to %d: %d\n", x, sum(x));

    return 0;
}

int sum(int n){
    int total = 0;
    int i;
    for (i = 1; i <= n; i++){
        total += i;
    }
    return total;
}
