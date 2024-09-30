#include <stdio.h>

struct Person {
    char name[80];
    int height;
    int weight;
};

struct Person p;

int main()
{
    struct Person p1;
    struct Person p2;

    scanf("%s", p1.name);
    scanf("%d", &p1.height);
    scanf("%d", &p1.weight);
    printf("Name: %s\n Height: %d cm\n Weight: %d kg\n", p1.name, p1.height, p1.weight);

    scanf("%s", p2.name);
    scanf("%d", &p2.height);
    scanf("%d", &p2.weight);
    printf("Name: %s\n Height: %d cm\n Weight: %d kg\n", p2.name, p2.height, p2.weight);

    return 0;
}
