#include <stdio.h>
#include <stdlib.h>

int main()
{
    char key;
    do
    {
        scanf(" %c", &key);
        if (key == 'q')
        {
            printf("You successfully exit this do-while loop.\n");
        }
        else
        {
            printf("You pressed %c.\n", key);
        }
    } while (key != 'q');
    

    return 0;
}