#include <stdio.h>
#include <stdlib.h>


int main(){

    int i = 10, k;
    int *ptr;
    ptr = &i;

    printf("name\taddr\tvalue\n");
    printf(" i\t%d\t%d\n", &i, i);
    printf(" k\t%d\t%d\n", &k, k);
    printf("ptr\t%d\t%d\n", &ptr, ptr);
    printf("*ptr\t%d\t%d\n", &*ptr, *ptr);

    k = *ptr;
    printf(" k\t%d\t%d\n", &k, k);

    *ptr = 100;  // i will be modified to 100
    printf("ptr\t%d\t%d\n", &ptr, ptr);
    printf(" i\t%d\t%d\n", &i, i);

    return 0;
}