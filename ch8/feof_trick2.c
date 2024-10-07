#include <stdio.h>
#include <stdlib.h>


int main(){

    char str[100];
    char c1;
    int i;
    FILE *f1 = fopen("r01.txt", "r");
    
    for (i=0; i<100; i++){
        fscanf(f1, "%s ", str);  // put a space after %s can avoid incomplete read
        // if (feof(f1)){
        //     break;
        // }
        printf("%s\n", str);
        if (feof(f1)){
            break;
        }
    }
    
    fclose(f1);
    return 0;
};