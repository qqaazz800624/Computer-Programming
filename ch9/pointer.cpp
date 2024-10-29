#include <iostream>

using namespace std;

int main() {

    int *ptr;
    ptr = new int(99);
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;

    *ptr = 100;
    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;

    delete ptr;
    
    return 0;
}