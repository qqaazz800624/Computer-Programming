#include <iostream>

using namespace std;

int main(){
    int i, n;
    int total = 0;
    char plus = '+';

    cin >> n;

    for(i=1; i<=n; i++){
        total += i;
        cout << i;

        if(i < n){
            cout << plus;
        }
    }
    cout << " = " << total << endl;

    return 0;
}