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

    int zero_flag = 0;  // To track when to print "零"

    // Process the ten-thousandth place
    if (num_10000 != 0)
    {
        printf("%s%s", num[num_10000], unit[4]);
        zero_flag = 1;
    }

    // Process the thousandth place
    if (num_1000 != 0)
    {
        printf("%s%s", num[num_1000], unit[3]);
        zero_flag = 1;
    }
    else if (zero_flag == 1) // Print "零" if the thousandth place is 0
    {
        printf("%s", num[0]);
        zero_flag = 0;
    }
    
    // Process the hundredth place
    if (num_100 != 0)
    {
        printf("%s%s", num[num_100], unit[2]);
        zero_flag = 1;
    }
    else if (zero_flag == 1) // Print "零" if the hundredth place is 0
    {
        printf("%s", num[0]);
        zero_flag = 0;
    }

    // Process the tenth place
    if (num_10 != 0)
    {
        printf("%s%s", num[num_10], unit[1]);
        zero_flag = 1;
    }
    else if (zero_flag == 1) // Print "零" if the tenth place is 0
    {
        printf("%s", num[0]);
        zero_flag = 0;
    }

    // Process the ones place
    if (num_1 != 0)
    {
        printf("%s", num[num_1]);
    }
    printf("元整\n");
    
    return 0;
}