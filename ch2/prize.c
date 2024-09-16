#include <stdio.h>

int main() {
    
    int score;

    scanf("%d", &score);

    if (score >= 95) {
        printf("2000 dollars\n");
    } else if (score >= 90) {
        printf("1000 dollars\n");
    } else if (score >= 80) {
        printf("500 dollars\n");
    } else {
        printf("0 dollars\n");
    }

    return 0;
}
