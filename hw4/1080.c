#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Name[100];
    int Lv;
    int Hp;
} Pokemon;

int compareByName(const void *a, const void *b) {
    return strcmp(((Pokemon *)a)->Name, ((Pokemon *)b)->Name);
}

int compareByLv(const void *a, const void *b) {
    return ((Pokemon *)a)->Lv - ((Pokemon *)b)->Lv;
}

int compareByHp(const void *a, const void *b) {
    return ((Pokemon *)a)->Hp - ((Pokemon *)b)->Hp;
}

void printPokemon(Pokemon *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s\nLv: %d\nHP: %d\n\n", p[i].Name, p[i].Lv, p[i].Hp);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);

    Pokemon *pokemons = (Pokemon *)malloc(n * sizeof(Pokemon));

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", pokemons[i].Name, &pokemons[i].Lv, &pokemons[i].Hp);
    }

    scanf("%d", &m);

    switch (m) {
        case 1:
            qsort(pokemons, n, sizeof(Pokemon), compareByName);
            break;
        case 2:
            qsort(pokemons, n, sizeof(Pokemon), compareByLv);
            break;
        case 3:
            qsort(pokemons, n, sizeof(Pokemon), compareByHp);
            break;
        case 0:
        default:
            break;
    }

    printPokemon(pokemons, n);
    free(pokemons);

    return 0;
}