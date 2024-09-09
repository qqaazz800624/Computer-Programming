#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int num1, num2;
    // scanf("%d %d", &num1, &num2);
    // printf("Hello %d C++ %d.\n", num1, num2);

    // scanf("%d", &num1);
    // printf("The third input is %d.\n", num1);

    int num1;
    double db;
    char ch;

    scanf(" %c", &ch); // in case of using space before %c
    scanf("%d", &num1);
    scanf("%lf", &db);

    printf("%c\n", ch);
    printf("%d\n", num1);
    printf("%lf\n", db);
    
    return 0;
}