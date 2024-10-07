#include <stdio.h>
#include <stdlib.h>


int main(){

    char str[100];
    char c1;
    int i;
    FILE *f1 = fopen("r01.txt", "r");
    //fscanf(f1, "%s", str);
    for (i=0; i<100; i++){
        fscanf(f1, "%c", &c1);
        if (feof(f1)){
            break;
        }
        printf("%c", c1);
    }
    
    fclose(f1);

    //printf("%s\n", str);
    return 0;
};