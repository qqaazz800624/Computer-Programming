#include <stdio.h>
#include <stdlib.h>

int main()
{
    char key;
    while (1)
    {
        scanf(" %c", &key);
        if (key == 'q')
        {
            printf("You successfully exit this while loop.\n");
            break;
        }
        else
        {
            printf("You pressed %c.\n", key);
        }
    }

    return 0;
}