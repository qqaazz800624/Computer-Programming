#include <iostream>

using namespace std;

int main() {

    int var = 10;
    int *ptr = &var;
    int &ref = var;
    cout << "var:\t" << var << endl;
    cout << "*ptr:\t" << *ptr << endl;
    cout << "ref:\t" << ref << endl;

    ref = 20;
    cout << "var:\t" << var << endl;
    cout << "*ptr:\t" << *ptr << endl;
    cout << "ref:\t" << ref << endl;

    *ptr = 30;
    cout << "var:\t" << var << endl;
    cout << "*ptr:\t" << *ptr << endl;
    cout << "ref:\t" << ref << endl;

    return 0;
}