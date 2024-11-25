#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>

using namespace std;

class Pokemon {
    private:
        string Name;
        int Lv;
        int HpMax;
        int HpCur;

    public:
        Pokemon();

        Pokemon(string name, int lv, int hp);

        ~Pokemon();

        void ShowInfo();
        void Attack(Pokemon &Target);
        void Defence(int damage);
        void Cure();
        void setData(string name, int lv, int hp);
};

#endif
