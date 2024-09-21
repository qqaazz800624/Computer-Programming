#include <stdio.h>
#include <stdlib.h>
void printAry(int n, int *p);
void AryZero(int n, int *p);

int main(){

    int a1[5] = {11, 22, 33, 44, 55};
    int a2[3] = {77,88,99};

    printAry(5, a1);
    printAry(3, a2);

    printAry(5, a1);
    AryZero(5, a1);
    printAry(5, a1);

    return 0;
}

void printAry(int n, int *p){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", p[i]);
    }
    puts("");
}

void AryZero(int n, int *p){
    int i;
    for(i = 0; i < n; i++){
        p[i] = 0;
    }
}