#include <stdio.h>


int main()
{
    double n1, n2, ans;
    char op;
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf(" %c", &op);  // space before %c is necessary to skip the newline character

    switch (op)
    {
    case '+':
        ans = n1 + n2;
        break;
    case '-':
        ans = n1 - n2;
        break;
    case '*':
        ans = n1 * n2;
        break;
    case '/':
        ans = n1 / n2;
        break;
    default:
        printf("Invalid operator\n");
        break;
    }
    printf("%.2f %c %.2f = %.2f\n", n1, op, n2, ans);

    return 0;
}