#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char ch1,ch2;

    
    putchar('A');
    putchar('B');
    putchar(65); // ASCII value of 'A'
    putchar(66); // ASCII value of 'B'
    putchar(165-100); // ASCII value of 'A': 165-100 = 65
    putchar('\n');

    // int i = 0;
    // for (i = 0; i < 128; i++) {
    //     printf("%3d: %c\n", i, i);
    // }

    char i = 0;
    for (i = 0; i < 127; i++) {
        printf("%3d: %c\n", i, i);
    }

    return 0;
}