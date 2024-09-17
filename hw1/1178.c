#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if (a>b && a>c){
    printf("True\n");
    }
    else{
    printf("False\n");
    }

    if (a<b && a<c){
    printf("True\n");
    }
    else{
    printf("False\n");
    }

    if (!(a>b && a>c)){
    printf("True\n");
    }
    else{
    printf("False\n");
    }

    if (!(a<b && a<c)){
    printf("True");
    }
    else{
    printf("False");
    }
    
    return 0;
}