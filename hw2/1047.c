#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 128 

int main(){

    char input[MAX_LENGTH];
    int i;
    int bit = 6;

    while(1){
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0'; 

        if (strcmp(input, "-1") == 0) {
            break;
        }

        for (i=0; input[i] != '\0'; i++){
            unsigned char ch = input[i];

            for (bit = 6; bit >= 0; bit--){
                if (ch & (1 << bit)){
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf(",");
        }
        printf("\n");

    }

    return 0;
}
