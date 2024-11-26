#include<iostream> 
#include "Pokemon_1116.h"
 
using namespace std;
 
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
    //Pikachu is unable to attack.
    //Mewtwo cannot attack fainted target Pikachu.
 
    cout << Name << " Attack " << Target.Name << " "
         << Lv << " Points." << endl;
    Target.Defence(Lv);
 
}

void Pokemon::Defence( int atkp ){
    int defp = 0; //此處防御力無用
    HpCur -= (atkp-defp);
 
    if(HpCur <= 0){
        cout << Name << " is fainted." << endl;
        HpCur = 0;
    }
}

void Pokemon::Cure(){
    cout << Name << " restore health." << endl;
    //回復體力
    HpCur = HpMax;
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
 
Pokemon::Pokemon(){
    Name = "No Name";
    Lv = 1;
    HpMax = 1;
    HpCur = 1;
}
 
Pokemon::Pokemon(string na, int lv, int hp){
    setData(na, lv, hp);
}
 
PokemonHealthCenter::PokemonHealthCenter(string na){
    Name = na;
}
void PokemonHealthCenter::Cure(Pokemon &p){
    cout << p.Name << " has restored health at " <<Name << ".\n";
    //回復 p 到滿血
    p.HpCur = p.HpMax;
}