#include <iostream>
#include <string.h>

using namespace std;

struct Person {
    string name;
    int height;
    int weight;
};
typedef struct Person person;

void show(int a){
    cout << "int a = " << a << endl;
}

void show(int a, int b){
    cout << "int a = " << a << ", b = " << b << endl;
}

void show(double a){
    cout << "double a = " << a << endl;
}


// pass by value
// void show(struct Person sp){
//     cout << "Name: " << sp.name << endl;
//     cout << "Height: " << sp.height << endl;
//     cout << "Weight: " << sp.weight << endl;
// }

// pass by reference: faster and more efficient
void show(struct Person &sp){
    cout << "Name: " << sp.name << endl;
    cout << "Height: " << sp.height << endl;
    cout << "Weight: " << sp.weight << endl;
}

//pass by address
void show(struct Person *sp){
    cout << "Name: " << sp->name << endl;
    cout << "Height: " << sp->height << endl;
    cout << "Weight: " << (*sp).weight << endl;  // same as sp->weight
}

int main() {

    person p;
    cin >> p.name >> p.height >> p.weight;

    show(p);
    show(&p);

    return 0;
}