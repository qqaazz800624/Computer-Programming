#include <stdio.h>

int main()
{
    int i;
    int sum = 0;
    int num_iter = 10;
    for (i=1; i <= num_iter; i++){
        //sum = sum + i;
        sum += i;
        printf("i = %d\n", i);
        printf("current sum = %d\n", sum);
    }
    printf("total sum = %d\n", sum);

    return 0;
}