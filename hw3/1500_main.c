#include <stdio.h>
#include <stdlib.h>
 
#include "1500_bag.h"
//#include "1500_bag.c"
//bag.c 在 自己的電腦上需要保留就好，上傳時千萬別留著。（如果是用devC++的話）

int main() {
    int i,n,k;
    int *a;
    //n=阿宅要買的東西 k=背包的容量
    scanf("%d%d",&n,&k);
    a = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        }
    ans(n,k,a);//進入ans 函式
    free(a);
    return 0;
}