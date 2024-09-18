#include <stdio.h>

int main() {
    
    char ch;
    ch = getchar();

    if (ch >= '0' && ch <= '9') {
        printf("You entered a digit.\n");
    } else if (ch >= 'A' && ch <= 'Z') {
        printf("You entered an uppercase letter.\n");
    } else if (ch >= 'a' && ch <= 'z') {
        printf("You entered a lowercase letter.\n");
        ch -= 32;
        printf("The uppercase letter is: %c\n", ch);
    } else {
        printf("You entered a special character.\n");
    }

    return 0;
}