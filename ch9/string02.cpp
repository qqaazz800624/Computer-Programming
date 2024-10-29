#include <iostream>

using namespace std;

int main() {

    string s1, s2;

    s1 = "apple";
    s2 = "banana";

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    int len1 = s1.length();
    for (int i=0; i < len1; i++){
        cout << s1[i] << " ";
    }
    cout << endl;

    return 0;
}