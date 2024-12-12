#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);

    size_t start = 0;

    while ((start = S1.find(S2, start)) != string::npos){
        size_t index = start;

        cout << index << "\t";

        if (index >= 2){
            cout << S1[index - 2] << S1[index - 1] << "+";
        } else if (index == 1){
            cout << " " << S1[index - 1] << "+";
        } else {
            cout << "  +";
        }

        cout << S2 << "+";

        if (index + S2.length()+1 < S1.length()){
            cout << S1[index + S2.length()] << S1[index + S2.length() + 1] << endl;
        } else if (index + S2.length() < S1.length()){
            cout << S1[index + S2.length()] << " " << endl;
        } else {
            cout << "  " << endl;
        }

        start = index + 1;
    }

    return 0;
}
