#include <iostream>
#include "show_1093.h"
 
using namespace std;
 
int main(int argc, char** argv) {
 
    int n1, n2;
    double n3, n4;
    char n5;   
    struct Person p1;
 
    cin >> n1 >> n2;
    cin >> n3 >> n4;
    cin >> n5;
    cin >> p1.name >> p1.height >> p1.weight;
 
    show(n1);
    show(n2);
    show(n3);
    show(n4);
    show(n5);
    show(n1, n2);
    show(n3, n4);
 
    show(p1);
 
    return 0;
}