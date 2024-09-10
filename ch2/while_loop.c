#include <stdio.h>
#include <stdlib.h>

int main()
{
    char key = 0;
    while (key != 'q'){
        scanf(" %c", &key);
        if (key == 'q'){
            printf("You successfully exit this while loop.\n");
        }
        else{
            printf("You pressed %c.\n", key);
        }
    }

    return 0;
}