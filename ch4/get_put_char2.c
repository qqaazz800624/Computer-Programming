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

    return 0;
}