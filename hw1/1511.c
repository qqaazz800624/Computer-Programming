#include <stdio.h>

int main()
{
    int time, heat, cool, final;
    scanf("%d %d %d", &time, &heat, &cool);
    if (time%2 == 1){
        final = 20 + heat*(time/2 + 1) - cool*(time/2);
    }
    else {
        final = 20 + heat*(time/2) - cool*(time/2 - 1);
    }
    printf("%d\n", final);

    return 0;
}