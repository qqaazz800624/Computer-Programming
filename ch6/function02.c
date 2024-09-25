#include <stdio.h>
#include <stdlib.h>

void hello();

int main(){
    printf("Going to call hello().\n");
    hello();
    printf("Already called hello().\n");
    return 0;
}

void hello(){
    printf("Hello\n");
    printf("Hello\n");
    printf("Hello\n");
}