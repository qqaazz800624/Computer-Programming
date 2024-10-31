#include <iostream>

using namespace std;

class Pokemon {
    public:
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
        };

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
        };

        void Defense(int n){
            HpCur -= n;
            if (HpCur <= 0){
                cout << Name << " fainted." << endl;
                HpCur = 0;
            }
        };

        void Cure(){
            cout << Name << " is cured." << endl;
            HpCur = HpMax;
        };

    private:
        string Name;
        int Lv;
        int HpCur;
        int HpMax;
};

void Pokemon::Show(){
    cout << "Name: " << Name << endl;
    cout << "Lv: " << Lv << endl;
    cout << "HP: " << HpCur << "/" << HpMax << endl;
};


int main(){

    Pokemon p1, p2;
    p1.SetData("Pikachu", 10, 15, 15);
    p2.SetData("Charmander", 15, 25, 25);

    p1.Attack(p2);
    p2.Attack(p1);
    p1.Attack(p2);
    p2.Attack(p1);

    p1.Cure();

    p1.Show();
    p2.Show();
    
    return 0;
}