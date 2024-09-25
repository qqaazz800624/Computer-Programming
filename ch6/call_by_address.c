#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main(){
    
    int num1 = 5;
    int num2 = 10;
    swap(&num1, &num2);
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    return 0;
}

void swap(int *pX, int *pY){
    int temp;
    temp = *pX;
    *pX = *pY;
    *pY = temp;
}