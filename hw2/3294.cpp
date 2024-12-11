#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i;
    int index;

    vector<string> mac_addresses(n);
    for (i = 0; i < n; ++i) {
        cin >> mac_addresses[i];
    }

    while (cin >> index) {
        if (index >= 0 && index < n) {
            cout << mac_addresses[index] << endl;
        } else {
            cerr << "Invalid index: " << index << endl;
        }
    }

    return 0;
}
