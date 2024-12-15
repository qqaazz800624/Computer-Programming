#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double n1, n2, ans;
    char command;

    cin >> n1 >> n2 >> command;

    switch(command){
        case '+':
            ans = n1 + n2;
            break;
        case '-':
            ans = n1 - n2;
            break;
        case '*':
            ans = n1 * n2;
            break;
        case '/':
            ans = n1 / n2;
            break;
        default:
            cout << "Invalid operator" << endl;
            break;
    }
    cout << fixed << setprecision(2) << n1 << " "
         << command << " " << n2 << " = " << ans << endl;

    return 0;
}