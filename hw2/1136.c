#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    
    scanf("%d", &N);
    
    int *A;
    A = (int *)malloc(N * sizeof(int));
    if (A == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i += 2) {
        int temp = A[i];
        A[i] = A[i+1];
        A[i+1] = temp;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);
    
    return 0;
}
