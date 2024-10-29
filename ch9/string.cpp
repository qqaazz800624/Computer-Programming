#include <iostream>
#include <string>

using namespace std;

int main() {

    string str;
    int n, i;

    cout << "Enter a string: ";
    cin >> str;

    n = str.length();
    cout << "The length of the string is " << n << endl;
    cout << "The characters in the string are: " << endl;
    for (i=0; i<n; i++){
        cout << "[" << i << "]:" << str[i] << endl;
    }
    
    return 0;
}