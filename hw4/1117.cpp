#include "Pokemon_1117.h"

Pokemon::Pokemon() {
    setData("No Name", 1, 1);
}

Pokemon::Pokemon(string name, int lv, int hp) {
    setData(name, lv, hp);
}

void Pokemon::setData(string name, int lv, int hp) {
    if (name.empty() || name.find_first_not_of(" \t\n") == string::npos) {
        cout << "Name can't be empty." << endl;
        Name = "No Name";
    } else {
        Name = name;
    }

    if (lv < 1) {
        cout << "Lv setting error." << endl;
        Lv = 1;
    } else {
        Lv = lv;
    }

    if (hp < 1) {
        cout << "Hp setting error." << endl;
        HpMax = 1;
        HpCur = 1;
    } else {
        HpMax = hp;
        HpCur = hp;
    }
}

void Pokemon::ShowInfo() {
    cout << "Name: " << Name << endl;
    cout << "Lv: " << Lv << endl;
    cout << "HP: " << HpCur << "/" << HpMax << endl;
    cout << endl;
}


Pokemon& Pokemon::operator>>(Pokemon &Target) {
    if (HpCur <= 0) {
        cout << Name << " is unable to attack." << endl;
        return *this;
    }
    if (Target.HpCur <= 0) {
        cout << Name << " cannot attack fainted target " << Target.Name << "." 
             << endl;
        return *this;
    }

    cout << Name << " Attack " << Target.Name << " " 
         << Lv << " Points." << endl;
    Target.Defence(Lv);

    return *this;
}

void Pokemon::Defence(int atkp) {
    HpCur -= atkp;
    if (HpCur <= 0) {
        HpCur = 0;
        cout << Name << " is fainted." << endl;
    }
}

void Pokemon::Cure() {
    HpCur = HpMax;
}

PokemonHealthCenter::PokemonHealthCenter(string name) {
    Name = name;
}

PokemonHealthCenter& PokemonHealthCenter::operator<<(Pokemon &p) {
    cout << p.Name << " has restored health at " << Name << "." << endl;
    p.HpCur = p.HpMax;  
    return *this;
}
