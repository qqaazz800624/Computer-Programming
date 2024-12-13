#include <iostream>
#include "MySwap.h"
 
using namespace std;
 
int main() {
 
    int n1, n2;
    cin >> n1 >> n2;
 
    MySwap(n1, n2);
 
    cout << n1 << endl << n2 << endl;
    return 0;
}