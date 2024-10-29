#include <iostream>

using namespace std;

int main() {

    int *ptr;
    int size, i;

    cout << "Please enter the size of the array: ";
    cin >> size;

    ptr = new int[size];
    cout << "Please enter the elements: " << endl;
    for (i=0; i<size; i++){
        cout << "ptr[" << i << "] = ";
        cin >> ptr[i];
    }
    for (i=0; i<size; i++){
        cout << "ptr[" << i << "] = " << ptr[i] << endl;
    }
    delete [] ptr;
    
    return 0;
}