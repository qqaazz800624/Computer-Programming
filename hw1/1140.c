#include <stdio.h>
#include <stdlib.h>


int main() {
    int i, j, n;

    scanf("%d", &n);

    for (i=1; i<=n; i++){
    printf("%d", i);
    }

    for (j=i-2; j>=1; j--){
    printf("%d", j);
    }
    printf("\n");
    
    return 0;
}