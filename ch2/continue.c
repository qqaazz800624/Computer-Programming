#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for (i=1; i<=10; i++){
        if (i == 4){
            continue;
        }
        printf("Floor %d\n", i);
    }

    return 0;
}