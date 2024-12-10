#ifndef subject_h
#define subject_h
#include "3225_observer.h"
#include <vector>
#include <iostream>

using namespace std;
 
class Subject {
    private:
        
        vector<Observer *> observers;
        string name;
    
    public:
        Subject(string name);
        void addObserver(Observer *observer);
        void notifyObservers(string message);
};
 
#endif