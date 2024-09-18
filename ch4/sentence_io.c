#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char str1[100];
    char str2[100];
    
    puts("This is sentence1.");
    puts("");
    puts("This is sentence2.");
    
    //gets(str1);
    scanf("%s", str1);
    fflush(stdin);  // Clear the input buffer
    gets(str2);

    puts(str1);
    puts(str2);

    return 0;
}