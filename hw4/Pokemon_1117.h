#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
using namespace std;

class Pokemon {
private:
    string Name;
    int Lv;
    int HpMax;
    int HpCur;

    void setData(string name, int lv, int hp);

public:
    Pokemon();
    Pokemon(string name, int lv, int hp);

    void ShowInfo();
    void Defence(int atkp);
    void Cure();

    Pokemon& operator>>(Pokemon &Target);

    friend class PokemonHealthCenter;
};

class PokemonHealthCenter {
private:
    string Name;

public:
    PokemonHealthCenter(string name);
    
    PokemonHealthCenter& operator<<(Pokemon &p);
};

typedef PokemonHealthCenter PC;

#endif
