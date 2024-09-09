#include <stdio.h>

int main()
{
    int x = 42;
    double y = 12.345;
    char c = 'A';

    printf("%d %lf %c\n", x, y, c);
    printf("|%15d|\n", x);
    printf("|%-15d|\n", x);
    printf("|%015d|\n", x);
    printf("|%10lf|\n", y);
    printf("|%10.3lf|\n", y);
    
    return 0;
}