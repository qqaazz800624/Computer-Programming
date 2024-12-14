#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

class Pokemon {
    private:
        string Name;
        int Lv;
        int Hp;

    public:
        Pokemon(){
            Name = "";
            Lv = 0;
            Hp = 0;
        }

        Pokemon(string name, int lv, int hp) {
            Name = name;
            Lv = lv;
            Hp = hp;
        }

        string getName() const { 
            return Name; 
        }

        int getLv() const { 
            return Lv; 
        }

        int getHp() const { 
            return Hp; 
        }

        void print() const {
            cout << "Name: " << Name << endl;
            cout << "Lv: " << Lv << endl;
            cout << "HP: " << Hp << endl << endl;
        }

        static bool compareByName(const Pokemon &a, const Pokemon &b) {
            return a.getName() < b.getName();
        }

        static bool compareByLv(const Pokemon &a, const Pokemon &b) {
            return a.getLv() < b.getLv();
        }

        static bool compareByHp(const Pokemon &a, const Pokemon &b) {
            return a.getHp() < b.getHp();
        }
};

void printPokemons(const vector<Pokemon> &pokemons) {
    for (size_t i = 0; i < pokemons.size(); ++i) {
        pokemons[i].print();
    }
}

int main() {
    int n, m;

    cin >> n;
    vector<Pokemon> pokemons;

    for (int i = 0; i < n; ++i) {
        string name;
        int lv, hp;
        cin >> name >> lv >> hp;
        pokemons.push_back(Pokemon(name, lv, hp));
    }

    cin >> m;
    switch (m) {
        case 1:
            sort(pokemons.begin(), pokemons.end(), Pokemon::compareByName);
            break;
        case 2:
            sort(pokemons.begin(), pokemons.end(), Pokemon::compareByLv);
            break;
        case 3:
            sort(pokemons.begin(), pokemons.end(), Pokemon::compareByHp);
            break;
        case 0:
        default:
            break;
    }

    printPokemons(pokemons);

    return 0;
}
