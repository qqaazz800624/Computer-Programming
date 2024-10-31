#include <iostream>

using namespace std;

class eCash {
    public:
    eCash(){
        balance = 0;
    }

    void store(int m){
        if (m < 0){
            cout << "eCash: Please enter a number > 0." << endl;
            return;
        }
        balance += m;
        cout << "eCash: You stored " << m << "." << endl;
    }

    void pay(int m){
        if (m < 0){
            cout << "eCash: Please enter a number > 0." << endl;
            return;
        }
        if (m > balance){
            cout << "eCash: Insufficient balance." << endl;
            return;
        }
        balance -= m;
        cout << "eCash: You spend " << m << "." << endl;
    }

    void display(){
        cout << "eCash: You remaining " << balance << "." << endl;
    }

    void quit(){
        cout << "eCash: Thank you. Bye Bye." << endl;
    }
        
    private:
        int balance;
};

int main(){

    eCash e;
    while (1){
        char enter;
        cin >> enter;
        if (enter == 'q'){
            e.quit();
            break;
        } else if (enter == 's'){
            int m;
            cin >> m;
            e.store(m);
        } else if (enter == 'p'){
            int m;
            cin >> m;
            e.pay(m);
        } else if (enter == 'd'){
            e.display();
        }
    }
    
    return 0;
}