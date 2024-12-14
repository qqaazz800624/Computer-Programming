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
        int m;

        switch(enter){
            case 's':
                cin >> m;
                e.store(m);
                break;
            case 'p':
                cin >> m;
                e.pay(m);
                break;
            case 'd':
                e.display();
                break;
            case 'q':
                e.quit();
                return 0;
            default:
                break;  
        }
    }
    
    return 0;
}