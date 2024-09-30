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
    struct Person *p2;

    p2 = &p1;  // p2 points to p1
    //gets(p2->name);
    scanf("%s", p2->name);
    scanf("%d", &p2->height);
    scanf("%d", &p2->weight);

    return 0;
}
