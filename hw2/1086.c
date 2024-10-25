#include <stdio.h>
#include <stdlib.h>


int main(){

    int N;
    char C1;
    double F;
    char S1[255];
    char C2;
    char S2[127];
    int i;

    scanf("%d", &N);
    scanf(" %c", &C1);
    scanf("%lf", &F);
    getchar();  // consume the newline character
    fgets(S1, sizeof(S1), stdin);  // read a line of text
    scanf(" %c", &C2);
    scanf("%s", S2);  // read a single word

    printf("%.2lf\n", N + F);

    int second;
    second = N + (int)C1;
    printf("%c %d\n", (char)second, second);

    int third;
    third = (int)C2 + (int)F;
    printf("%c %d\n", (char)third, third);

    for (i = 0; i < 255; i++){
        if (S1[i] >= 'A' && S1[i] <= 'Z'){
            S1[i] += 32;
        }
        if (S1[i] == '\0'){
            break;
        }
    }
    printf("%s", S1);

    for (i = 0; i < 127; i++){
        if (S2[i] >= 'a' && S2[i] <= 'z'){
            S2[i] -= 32;
        }
        if (S2[i] == '\0'){
            break;
        }
    }
    printf("%s\n", S2);

    return 0;
}