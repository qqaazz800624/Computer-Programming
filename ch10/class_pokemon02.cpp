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
        void Attack(Pokemon &target);
        void Defense(int n);
        void Cure();

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
    p1.SetData("Pikachu", 10, 15, 14);
    p2.SetData("Charmander", 15, 25, 25);
    p1.Show();
    p2.Show();
    
    return 0;
}