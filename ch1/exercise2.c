#include <stdio.h>

int main()
{
    // double a, b, answer;
    // scanf("%lf%lf", &a, &b);
    // answer = a + b;
    // printf("%.2f + %.2f = %.2f\n", a, b, answer);

    double a, b;
    scanf("%lf%lf", &a, &b);

    printf("請輸入兩個數字: 5.1 2.3\n");
    printf("計算結果：\n");
    printf("%.2f + %.2f = %.2f\n", a, b, a + b);
    printf("%.2f - %.2f = %.2f\n", a, b, a - b);
    printf("%.2f * %.2f = %.2f\n", a, b, a * b);
    printf("%.2f / %.2f = %.2f\n", a, b, a / b);

    return 0;
}