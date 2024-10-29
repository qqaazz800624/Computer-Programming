#include <iostream>

using namespace std;

void increment(int &n){
    n = n + 1;
}

int main() {

    int x = 10;
    increment(x);
    cout << x << endl;

    return 0;
}