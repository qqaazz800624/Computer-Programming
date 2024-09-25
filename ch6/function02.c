#include <stdio.h>
#include <stdlib.h>

#define N 5

void hello(int n);

int main(){
    printf("Going to call hello().\n");
    hello(N);
    printf("Already called hello().\n");
    return 0;
}

void hello(int n){
    int i;
    for (i = 0; i < n; i++){
        printf("Hello\n");
    }
    return;
}