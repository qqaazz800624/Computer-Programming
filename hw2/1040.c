#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 128

void upper(char *a);

int main() {
    char input[MAX_LENGTH];
    int i;
    
    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        input[strcspn(input, "\n")] = '\0';
        
        if (strcmp(input, "-1") == 0) {
            break;
        }
        
        upper(input);
        
        printf("%s\n", input);
    }
    
    return 0;
}

void upper(char *a){
    int i=0;
    while (1){
        if (a[i] >= 'a' && a[i] <= 'z'){
            a[i] -= 32;
        } else if (a[i] == '\0'){
            break;
        }
        i++;
    }
}