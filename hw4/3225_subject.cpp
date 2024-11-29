#include "3225_subject.h"
 
Subject::Subject(std::string name){
    this->name = name;
    this->observers = std::vector<Observer *>();
}

void Subject::addObserver(Observer *observer){
    observers.push_back(observer);
}

void Subject::notifyObservers(std::string message){
    size_t i;
    for (i=0; i < observers.size(); ++i){
        observers[i]->notify(message, name);
    }
}
 
// TODO: 完成其餘成員函數