#include "3225_subject.h"
#include <iostream>

using namespace std;
 
Subject::Subject(string name){
    this->name = name;
    this->observers = vector<Observer *>();
}

void Subject::addObserver(Observer *observer){
    observers.push_back(observer);
}

void Subject::notifyObservers(string message){
    size_t i;
    for (i=0; i<observers.size(); ++i){
        observers[i]->notify(message, name);
    }
}
 
// TODO: 完成其餘成員函數