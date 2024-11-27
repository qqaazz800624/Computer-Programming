#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
using namespace std;

class Pokemon {
    public:
        Pokemon();
        Pokemon(string name, int lv, int hp);
        void ShowInfo();
        void Defence(int atkp);
        void Cure();

        Pokemon& operator>>(Pokemon &Target);

    friend class PokemonHealthCenter;

    private:
        void setData(string name, int lv, int hp);
        string Name;
        int Lv;
        int HpMax;
        int HpCur;
};

class PokemonHealthCenter {
    public:
        PokemonHealthCenter(string name);
        PokemonHealthCenter& operator<<(Pokemon &p);

    private:
        string Name;
};

typedef PokemonHealthCenter PC;

#endif
