#include <stdio.h>
#include <string.h>

int main() {
    
    char a[80] = "Hello";
    char b[80];

    scanf("%s", b);

    if (strcmp(a, b) == 0){
        printf("輸入字串正確\n");
    }  else {
        printf("輸入字串錯誤\n");
    }

    return 0;
}