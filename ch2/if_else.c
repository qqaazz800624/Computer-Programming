#include <stdio.h>

int main()
{
    int score;
    printf("請輸入您的分數：");
    scanf("%d", &score);
    if (score < 60)
    {
        printf("不及格\n");
    }
    else
    {
        printf("及格\n");
    }

    return 0;
}