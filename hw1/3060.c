#include <stdio.h>


int main()
{
    int num;
    int position = 0;
    int sum = 0;
    int count = 0;
    int max, min;
    int max_position = 0, min_position = 0;
    double average;

    while (1){
        scanf("%d", &num);
        if (num == -1){
            break;
        }
        if (num <= 0){
            continue;
        }

        position++;
        sum += num;
        count++;

        if (count == 1){
            max = num;
            min = num;
            max_position = position;
            min_position = position;
        } else {
            if (num > max){
                max = num;
                max_position = position;
            }
            if (num < min){
                min = num;
                min_position = position;
            }
        }
    }

    average = (double)sum / count;
    printf("%d\n", sum);
    printf("%.1f\n", average);
    printf("%d\n", max);
    printf("%d\n", max_position);
    printf("%d\n", min);
    printf("%d\n", min_position);

    return 0;
}