#include <stdio.h>
#include <stdlib.h>

#define N 3

struct _Pokemon{
    char Name[100];
    int Lv;
    int Hp;
};
typedef struct _Pokemon Pokemon;

int main(){

    Pokemon p[N];
    int i, n;
    int found = 0;

    for (i=0; i<N; i++){
        scanf("%s", p[i].Name);
        scanf("%d", &p[i].Lv);
        scanf("%d", &p[i].Hp);
    }

    scanf("%d", &n);

    for (i=0; i<N; i++){
        if (p[i].Lv >= n){
            found = 1;
            printf("Name: %s\n", p[i].Name);
            printf("Lv: %d\n", p[i].Lv);
            printf("HP: %d\n", p[i].Hp);
            printf("\n");
        }
    }

    if (found == 0){
        printf("not found\n");
    }

    return 0;
}