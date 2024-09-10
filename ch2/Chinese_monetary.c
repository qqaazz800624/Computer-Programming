#include <stdio.h>
#include <stdlib.h>

int main()
{
    int money;
    char *unit[] = {"元", "拾", "佰", "仟", "萬"};
    char *num[] = {"零", "壹", "貳", "參", "肆", "伍", "陸", "柒", "捌", "玖"};

    printf("請輸入金額: ");
    scanf("%d", &money);

    int num_1, num_10, num_100, num_1000, num_10000;
    num_1 = money % 10;
    num_10 = (money / 10) % 10;
    num_100 = (money / 100) % 10;
    num_1000 = (money / 1000) % 10;
    num_10000 = (money / 10000) % 10;

    if (num_10000 != 0)
    {
        printf("%s", num[num_10000]);
        printf("%s", unit[4]);
    }
    if (num_1000 != 0)
    {
        printf("%s", num[num_1000]);
        printf("%s", unit[3]);
    }
    if (num_100 != 0)
    {
        printf("%s", num[num_100]);
        printf("%s", unit[2]);
    }
    if (num_10 != 0)
    {
        printf("%s", num[num_10]);
        printf("%s", unit[1]);
    }
    if (num_1 != 0)
    {
        printf("%s", num[num_1]);
    }
    printf("元整\n");
    
    return 0;
}