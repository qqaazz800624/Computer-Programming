#include <stdio.h>
#include <stdlib.h>

struct Pokemon {
    char name[80];
    int Lv;
    int Hp;
};

int main()
{
    struct Pokemon p1, p2={"Charmander", 15, 20};

    scanf("%s", p1.name);
    scanf("%d", &p1.Lv);
    scanf("%d", &p1.Hp);

    printf("Name: %s\n", p1.name);
    printf("Lv: %d\n", p1.Lv);
    printf("Hp: %d\n", p1.Hp);

    printf("Name: %s\n", p2.name);
    printf("Lv: %d\n", p2.Lv);
    printf("Hp: %d\n", p2.Hp);

    return 0;
}
