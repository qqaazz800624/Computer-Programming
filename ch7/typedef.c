#include <stdio.h>
#include <stdlib.h>

#define PEOPLE 2

struct _Person {
    char name[80];
    int height;
    int weight;
};
typedef struct _Person Person;


int main()
{
    Person p[PEOPLE];

    int i;
    for (i = 0; i < PEOPLE; i++) {
        scanf("%s", p[i].name);
        scanf("%d", &p[i].height);
        scanf("%d", &p[i].weight);
        printf("Name: %s\n Height: %d\n Weight: %d\n", p[i].name, p[i].height, p[i].weight);
    }

    return 0;
}
