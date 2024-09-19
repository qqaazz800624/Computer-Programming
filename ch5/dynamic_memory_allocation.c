#include <stdio.h>
#include <stdlib.h>


int main(){

    int *ptr, n=4;
    /*Dynamic Memory Allocation*/
    ptr = (int*)malloc(sizeof(int)*n);
    /*release memory*/
    free(ptr);

    return 0;
}