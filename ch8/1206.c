#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *f1;
    char str[128];
    scanf("%s", str);
    f1 = fopen(str, "r");

    char ch;

    while (1){
        fscanf(f1, "%c", &ch); // Don't put a space after %c
        if (feof(f1)){
            break;
        }
        putchar(ch);
    }
    printf("\n");
    fclose(f1);

    return 0;
};