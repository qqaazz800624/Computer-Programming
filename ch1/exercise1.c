#include <stdio.h>

int main()
{
    int up, down, height;
    scanf("%d %d %d", &up, &down, &height);
    double answer = (double)((up + down) * height) / 2; // change to double to get the decimal point
    printf("%.1f\n", answer);  // print the answer with 1 decimal point

    return 0;
}