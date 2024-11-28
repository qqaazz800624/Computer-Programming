#ifndef SHOW_H
#define SHOW_H


struct Person {
    char name[100];  
    int height;      
    int weight;      
};


void show(int);
void show(double);
void show(int, int);
void show(struct Person);

#endif