#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    int *arr;
    int i;
    int ans;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int)*n);
    
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    if(n%2==0){
        ans = (arr[n/2-1]+arr[n/2]+1)/2;
    }
    else{
        ans = arr[n/2];
    }
    printf("%d\n", ans);
    free(arr);
    return 0;
}
