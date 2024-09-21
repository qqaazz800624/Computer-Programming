#include <stdio.h>
#include <math.h>

int isArmstrong(int num){
    int sum = 0;
    int originalNum = num;
    int digit_len = 0;
    int digit = 0;
    
    while(num != 0){
        num /= 10;
        digit_len++;
    }

    num = originalNum;
    while(num != 0){
        digit = num % 10;
        sum += pow(digit, digit_len);
        num /= 10;
    }
    
    return sum == originalNum;
}

int main()
{
    int n, m;
    int found = 0;
    int i;

    scanf("%d %d", &n, &m);
    for (i = n; i <= m; i++){
        if (isArmstrong(i)){
            if (found){
                printf(" & ");
            }
            printf("%d", i);
            found = 1;
        }
    }
    if (!found){
        printf("none");
    }
    printf("\n");

    return 0;
}