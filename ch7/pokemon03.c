#include <stdio.h>
#include <stdlib.h>

#define N 3

struct _Pokemon {
    char name[80];
    int Lv;
    int Hp;
};
typedef struct _Pokemon Pokemon;

int main()
{
    Pokemon p[N];

    int i;

    for (i=0; i<N; i++) {
        scanf("%s", p[i].name);
        scanf("%d", &p[i].Lv);
        scanf("%d", &p[i].Hp);
    }

    for (i=0; i<N; i++) {
        printf("Name: %s\n", p[i].name);
        printf("Lv: %d\n", p[i].Lv);
        printf("Hp: %d\n", p[i].Hp);
    }

    return 0;
}
