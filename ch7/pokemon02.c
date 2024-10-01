#include <stdio.h>
#include <stdlib.h>

struct Pokemon {
    char name[80];
    int Lv;
    int Hp;
};

int main()
{
    struct Pokemon p1={"Charmander", 15, 20};
    struct Pokemon *p2;
    p2 = &p1; // *p2 = p1; 

    printf("Name: %s\n", (*p2).name);
    printf("Lv: %d\n", (*p2).Lv);
    printf("Hp: %d\n", p2 -> Hp);

    return 0;
}
