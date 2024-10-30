#include <iostream>

using namespace std;

class Pokemon {
    public:
        void Show();
        void Attack(Pokemon &target);
        void Defense(int n);
        void Cure();
        
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

    Pokemon p1={"Pikachu", 10, 7, 10},
            p2={"Charmander", 15, 25, 25};
    p1.Show();
    p2.Show();
    
    return 0;
}