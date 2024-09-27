#include <stdio.h>
#include <stdlib.h>

void upper(char *a);

int main(){
    
    char str[80];

    gets(str);
    upper(str);

    printf("%s\n", str);

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
