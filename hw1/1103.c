#include <stdio.h>

int main()
{
    int money;
    char *unit[] = {"", "拾", "佰", "仟", "萬"};
    char *num[] = {"零", "壹", "貳", "參", "肆", "伍", "陸", "柒", "捌", "玖"};
    
    //printf("請輸入金額: ");
    scanf("%d", &money);

    if (money < 1 || money > 99999) {
        printf("out of range\n");
        return 0;
    }
    
    // Initialize an array to hold each digit of the money
    int digits[5];
    
    // Extract each digit of the money from ones to ten-thousands place
    for (int i = 0; i < 5; i++) {
        digits[i] = money % 10;
        money /= 10;
    }
    
    int zero_flag = 0;  // To track if we need to print a "零"
    int printed = 0;    // Track if any non-zero number has been printed

    // Traverse from the highest place to the lowest place (ten-thousands to ones)
    for (int i = 4; i >= 0; i--) {
        if (digits[i] != 0) {
            if (zero_flag) {   // check whether zero_flag is non-zero
                printf("%s", num[0]); // Print "零" before a non-zero digit
                zero_flag = 0;        // Reset flag
            }
            printf("%s%s", num[digits[i]], unit[i]);
            printed = 1; // Mark that a digit has been printed
        } else if (printed) {
            // If zero encountered after non-zero digits, set flag to print "零" later
            zero_flag = 1;
        }
    }

    printf("元整\n");  // End with "整"
    
    return 0;
}
