#include <stdio.h>

int main(int argc, char *argv[])
{
    int numL, numS;
    int n = 0;
    scanf("%d %d", &numL, &numS);
    while (numS != numL)
    {
        if (numS > numL){
            numS -= 2;
            n += 1;
        }
        else {
            numS += 5;
            n += 1;
        }
    }
    printf("%d", n);
    return 0;
}