#include <iostream>
#include "show_1093.h"
 
using namespace std;
 
void show(int x)
{
    cout << "1 int x="<<x << endl;
}
 
void show(double x)
{
    cout << "1 double x="<< x << endl;
}
 
void show(int x, int y)
{
    cout << "2 int x="<< x << ", y="<< y << endl;
}
 
void show(struct Person p)
{
    cout << "Name: " << p.name << endl;
    cout << "Height: " << p.height << " cm" << endl;
    cout << "Weight: " << p.weight << " kg" << endl;
}