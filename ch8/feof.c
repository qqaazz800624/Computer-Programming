#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *f1;
    f1 = fopen("abc.txt", "r");
    char str[128];

    while (1){
        fscanf(f1, "%s ", str);  // put a space after %s to read the next word
        puts(str);

        if (feof(f1)){
            break;
        }
    }

    fclose(f1);

    return 0;
};