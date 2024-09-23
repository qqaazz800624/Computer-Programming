#include <stdio.h>
#include <stdlib.h>

int main()
{
    int time_spent = 0;
    int prev_height = 0, final_height = 0;
    int current_height;
    char ch;

    scanf(" %c", &ch);
    
    while (1){
        scanf(" %c", &ch);
        if (ch == 'B'){
            if (prev_height == final_height){
                time_spent += 5;
             } else if (prev_height > final_height){
                time_spent += (prev_height - final_height)*6;
            }
            break;
        } else {
            ungetc(ch, stdin);

            scanf("%d", &current_height);

            if (current_height == prev_height){
                time_spent += 5;
            } else if (current_height > prev_height){
                time_spent += (current_height - prev_height)*10;
            } else {
                time_spent += (prev_height - current_height)*6;
            }

            prev_height = current_height;
        }
    }

    printf("%d\n", time_spent);

    return 0;
}