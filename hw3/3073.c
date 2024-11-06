#include <stdio.h>

void return2num(int n, int *factRst, int *sumRst);

int main() {
    int n;
    int factorialResult, sumResult;

    if (scanf("%d", &n) != 1) {
        n = 0; 
    }

    return2num(n, &factorialResult, &sumResult);

    printf("%d\n", factorialResult);
    printf("%d\n", sumResult);

    return 0;
}

void return2num(int n, int *factRst, int *sumRst) {
    if (n < 0) {
        *factRst = 1;
        *sumRst = 0;
        return;
    }
    
    *factRst = 1;
    *sumRst = 0;

    for (int i = 1; i <= n; i++) {
        *factRst *= i;
        *sumRst += i;
    }
}
