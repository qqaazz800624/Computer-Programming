#include <stdio.h>


int main()
{
    // int a1 = 46, a2 = 5;
    // double b1 = 46, b2 = 5;
    // double x, y;
    // x = a1 / a2; // x = 9
    // y = b1 / b2; // y = 9.2

    // printf("x = %.3f\n", x); // x = 9
    // printf("y = %.3f\n", y); // y = 9.200000

    // x = (double)a1/a2; // x = 9.2

    int a = 0;
    int b;

    a += 10; // a = 10
    b = a++; // b = 10, a = 11
    b = ++a; // b = 12, a = 12
    b = a--; // b = 12, a = 11
    b = --a; // b = 10, a = 10
    
    return 0;
}