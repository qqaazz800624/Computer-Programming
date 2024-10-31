#include <iostream>

using namespace std;

class Pokemon {
    public:
        Pokemon(){
            Name = "No name";
            Lv = 1;
            HpCur = 0;
            HpMax = 0;
            tools = new string[100];
        }

        Pokemon(string na, int lv, int hpc, int hpm){
            SetData(na, lv, hpc, hpm);
            tools = new string[100];
        }

        ~Pokemon(){
            cout << Name << " is released." << endl;
            delete [] tools;
        }

        void Show();

        void SetData(string na, int lv, int hpc, int hpm){
            
            if (hpc > hpm){
                cout << "Error: HP current is greater than HP max" << endl;
                return;
            }

            Name = na;
            Lv = lv;
            HpCur = hpc;
            HpMax = hpm;
        }

        void Attack(Pokemon &target){
            if (HpCur <= 0){
                cout << Name << " cannot attack." << endl;
                return;
            }
            if (target.HpCur <= 0){
                cout << "Target: " << target.Name << " is fainted, cannot attack." << endl;
                return;
            }
            cout << Name << " attacks " << target.Name << " " << Lv << " points." << endl;
            target.Defense(Lv);
        }

        void Defense(int n){
            HpCur -= n;
            if (HpCur <= 0){
                cout << Name << " fainted." << endl;
                HpCur = 0;
            }
        }

        void Cure(){
            cout << Name << " is cured." << endl;
            HpCur = HpMax;
        }

    friend class PokemonCenter;

    private:
        string Name;
        int Lv;
        int HpCur;
        int HpMax;
        string *tools;
};

void Pokemon::Show(){
    cout << "Name: " << Name << endl;
    cout << "Lv: " << Lv << endl;
    cout << "HP: " << HpCur << "/" << HpMax << endl;
}

class PokemonCenter{
    public:
        PokemonCenter(string na){
            Name = na;
        }
        void Cure(Pokemon &pk){
            pk.HpCur = pk.HpMax;
        cout << pk.Name << " is healed at " << Name << " Center." << endl;
        }
    private:
        string Name;
        
};

int main(){

    Pokemon p1("Pikachu", 10, 15, 15), p2("Charmander", 15, 25, 25);
    PokemonCenter pc1("NTU Health");

    p1.Attack(p2);
    p2.Attack(p1);

    pc1.Cure(p1);
    pc1.Cure(p2);

    p1.Show();
    p2.Show();
    
    return 0;
}