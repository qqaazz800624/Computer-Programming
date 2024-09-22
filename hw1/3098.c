#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input;
    int current_num;
    int count = 0;
    int prev_num = 0;

    while (1){
        scanf(" %c", &input);

        if (input == 'q'){
            break;
        }

        current_num = input - '0';
        if (current_num >= 0 && current_num <= 9){
            if (prev_num == 1 && current_num == 9){
                count += 1;
            }
            prev_num = current_num;
        }
    }
    printf("%d\n", count);

    return 0;
}