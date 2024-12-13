#ifndef SHOW_H
#define SHOW_H

using namespace std;

struct Person {
    string name;  
    int height;      
    int weight;      
};


void show(int);
void show(double);
void show(int, int);
void show(struct Person);

#endif