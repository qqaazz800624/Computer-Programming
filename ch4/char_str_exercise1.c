#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char str1[100];

    gets(str1);

    int i;
    for (i=0; i<100; i++){
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] = str1[i] - 32;
        }
        if (str1[i] == '\0') {
            break;
        }
    } 

    puts(str1);

    return 0;
}