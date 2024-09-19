#include <stdio.h>
#include <stdlib.h>


int main(){

    int *p;
    int a = 70;

    p = &a;
    printf("Address of a: %p\n", &a);

    return 0;
}