#include <stdio.h>


int main(){
    
    int n, left, extra, count;
    scanf("%d", &n);

    left = n%4;
    extra = n/4;
    count = n;
    count += extra;

    while ((left + extra) >=4){
        n = left + extra;
        left = n%4;
        extra = n/4;
        count += extra;
    }
    if (left + extra == 3){
        count += 1;
    }
    printf("%d\n", count);

    return 0;
}