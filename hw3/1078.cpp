#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define N 3

class Pokemon {
    public:
        string Name;
        int Lv;
        int Hp;
};

int main() {
    
    vector<Pokemon> p(N);
    int i, n;
    int found = 0;

    for (i = 0; i < N; i++) {
        cin >> p[i].Name;
        cin >> p[i].Lv;
        cin >> p[i].Hp;
    }

    cin >> n;

    for (i = 0; i < N; i++) {
        if (p[i].Lv >= n) {
            found = 1;
            cout << "Name: " << p[i].Name << endl;
            cout << "Lv: " << p[i].Lv << endl;
            cout << "HP: " << p[i].Hp << endl;
            cout << endl;
        }
    }

    if (found == 0) {
        cout << "not found" << endl;
    }
    
    return 0;
}
