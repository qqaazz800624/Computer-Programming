#include <iostream>
#include "Pokemon_1110.h"

Pokemon::Pokemon() {
    Name = "No Name";
    Lv = 1;
    HpMax = 1;
    HpCur = 1;
}

Pokemon::Pokemon(string name, int lv, int hp) {
    setData(name, lv, hp);
}

Pokemon::~Pokemon() {
    cout << Name << " has returned to the nature." << endl;
}

void Pokemon::setData(string name, int lv, int hp) {
    if (name.empty()){
        cout << "Name setting error." << endl;
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

void Pokemon::Attack(Pokemon &Target) {
    if (HpCur <= 0) {
        cout << Name << " cannot attack." << endl;
        return;
    }
    if (Target.HpCur <= 0) {
        cout << Target.Name << " has already fainted." << endl;
        return;
    }

    cout << Name << " attacks " << Target.Name << "!" << endl;
    Target.Defence(Lv);
}

void Pokemon::Defence(int damage) {
    if (HpCur > 0) { 
        HpCur -= damage;
        if (HpCur <= 0) {
            HpCur = 0;
            cout << Name << " fainted." << endl;
        }
    }
}

void Pokemon::Cure() {
    if (HpCur == HpMax) {
        cout << Name << " is already at full health." << endl;
    } else {
        cout << Name << " is cured." << endl;
        HpCur = HpMax;
    }
}
