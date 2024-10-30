#include <iostream>
#include <string.h>

using namespace std;


// pass by value
/*
void MySwap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "by value a= " << a << ", b= " << b << endl;
    
}

int main() {

    int x = 10, y = 20;
    MySwap(x, y);
    cout << "in main x= " << x << ", y= " << y << endl;

    return 0;
}
*/


// pass by reference: higher efficiency
/*
void MySwap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "by reference a= " << a << ", b= " << b << endl;
    
}

int main() {

    int x = 10, y = 20;
    MySwap(x, y);
    cout << "in main x= " << x << ", y= " << y << endl;

    return 0;
}
*/

// pass by address: high readability

void MySwap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "by address *a= " << *a << ", *b= " << *b << endl;
    
}

void MySwap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "by value a= " << a << ", b= " << b << endl;
    
}


int main() {

    int x = 10, y = 20;
    MySwap(x, y); // pass by value

    MySwap(&x, &y);  // pass by address: 函數重載 (overload) --> C++ 可以有相同名稱的函數，只要參數型態不同且可以辨識即可
    cout << "in main x= " << x << ", y= " << y << endl;

    return 0;
}