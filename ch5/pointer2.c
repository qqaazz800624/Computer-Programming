#include <stdio.h>
#include <stdlib.h>


int main(){

    int *p;
    int a = 70, b;

    p = &a;
    b = *p + 1;
    *p = 80;  // a will be modified to 80

    return 0;
}