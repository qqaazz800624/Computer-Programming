#include<iostream> 
#include "1116_Pokemon.h"
 
using namespace std;
 
Pokemon::Pokemon(){
    setData("No Name", 1, 1);
}

Pokemon::Pokemon(string na, int lv, int hp){
    setData(na, lv, hp);
}

void Pokemon::setData(string name, int lv, int hp){
    if(name.empty() || name.find_first_not_of(" \t\n") == string::npos){
        cout << "Name can't be empty.\n";
        name = "No Name";    
    }
    if(lv < 1){
        cout << "Lv setting error.\n";
        lv = 1;    
    }
    if(hp < 1){
        cout << "Hp setting error.\n";
        hp = 1;    
    }
 
    Name = name;
    Lv = lv;
    HpCur = HpMax = hp;
}

void Pokemon::ShowInfo(){
    cout << "Name: " << Name << endl;
    cout << "Lv: " << Lv << endl;
    cout << "HP: " << HpCur << "/" << HpMax << endl << endl;
}
 
void Pokemon::Attack(Pokemon &Target){
    if(HpCur <= 0){
        cout << Name << " is unable to attack." << endl;
        return;
    }
    if(Target.HpCur <= 0){
        cout << Name << " cannot attack fainted target " << Target.Name << "." <<endl;
        return;
    }
 
    cout << Name << " Attack " << Target.Name << " "
         << Lv << " Points." << endl;
    Target.Defence(Lv);
}

void Pokemon::Defence(int atkp){
    int defp = 0; 
    HpCur -= (atkp-defp);
 
    if(HpCur <= 0){
        cout << Name << " is fainted." << endl;
        HpCur = 0;
    }
}

void Pokemon::Cure(){
    cout << Name << " restore health." << endl;
    HpCur = HpMax;
}

 
PokemonHealthCenter::PokemonHealthCenter(string name){
    this -> Name = name;
}
void PokemonHealthCenter::Cure(Pokemon &p){
    cout << p.Name << " has restored health at " << this -> Name << ".\n";
    p.HpCur = p.HpMax;
}