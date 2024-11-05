#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K); 

    int *items = (int *)malloc(N * sizeof(int));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &items[i]);
    }

    int count = 0;        
    int total_volume = 0; 

    for (int i = 0; i < N; i++) {
        if (items[i] <= K) {
            total_volume += items[i];
            count++;
        }
    }

    printf("%d %d\n", count, total_volume); 
    free(items); 

    return 0;
}
