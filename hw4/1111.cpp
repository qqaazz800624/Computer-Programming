#include <iostream>
#include "Pokemon_1111.h"

Pokemon::Pokemon() {
    Name = "No Name";
    Lv = 1;
    HpMax = 1;
    HpCur = 1;
    items = new string[Lv];
    itemNum = 0;
}

Pokemon::Pokemon(string name, int lv, int hp) {
    setData(name, lv, hp);
    items = new string[Lv];
    itemNum = 0;
}

Pokemon::~Pokemon() {
    cout << Name << " has returned to the nature." << endl;
    delete[] items;
}

void Pokemon::setData(string na, int lv, int hp){
    if (na.empty() || na.find_first_not_of(" \t\n") == string::npos){
        cout << "Name can't be empty." << endl;
        Name = "No Name";
    } else {
        Name = na;
    }

    if (lv < 1){
        cout << "Lv setting error." << endl;
        Lv = 1;
    } else {
        Lv = lv;
    }

    if (hp < 1){
        cout << "Hp setting error." << endl;
        HpMax = 1;
        HpCur = 1;
    } else {
        HpMax = hp;
        HpCur = hp;
    }
}

void Pokemon::addItem(string item){
    if (itemNum >= Lv){
        cout << Name << " is full, cannot carry " << item << "." << endl;
        return;
    }
    items[itemNum] = item;
    itemNum++;
}

void Pokemon::ShowInfo(){
    int i;
    cout << "Name: " << Name << endl;
    cout << "Lv: " << Lv << endl;
    cout << "HP: " << HpCur << "/" << HpMax << endl;
    cout << "Items: ";
    for (i = 0; i < itemNum; i++){
        cout << items[i] << " ";
    }
    cout << endl << endl;
}

void Pokemon::Attack(Pokemon &Target){
    if (HpCur <= 0){
        cout << Name << " cannot attack." << endl;
        return;
    }
    if (Target.HpCur <= 0){
        cout << Target.Name << " has already fainted." << endl;
        return;
    }
    cout << Name << " attacks " << Target.Name << "!" << endl;
    Target.Defence(Lv);
}

void Pokemon::Defence(int n){
    if (HpCur > 0){
        HpCur -= n;
        if (HpCur <= 0){
            HpCur = 0;
            cout << Name << " fainted." << endl;
        }
    }
}

void Pokemon::Cure(){
    if (HpCur == HpMax){
        cout << Name << " is already at full health." << endl;
    } else {
        cout << Name << " is cured." << endl;
        HpCur = HpMax;
    }
}