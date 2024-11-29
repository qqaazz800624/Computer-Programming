#include <iostream>
#include "3225_subject.h"
#include "3225_observer.h"
 
using namespace std;
 
vector<string> split(string text, string delimiter){
    size_t pos = 0;
    std::string token;
    vector<string> result;
    string temp = text;
    while ((pos = temp.find(delimiter)) != std::string::npos) {
        token = temp.substr(0, pos);
        result.push_back(token);
        temp.erase(0, pos + delimiter.length());
    }
 
    result.push_back(temp);
    return result;
}
 
int main() {
    string name;
    int n, m;
 
    getline(cin, name);
    Subject subject(name);
 
    cin >> n;
    cin.ignore();
 
    for (int i=0; i<n; i++) {
        string line;
        getline(cin, line);
        vector<string> components = split(line, ",");
        Observer *observer = NULL;
        if(components[0].compare("PC") == 0){
            observer = new PCDevice(components[1]);
        } else if(components[0].compare("iOS") == 0){
            observer = new iOSDevice(components[1]);
        } else {
            observer = new AndroidDevice(components[1]);
        }
 
        subject.addObserver(observer);
    }
 
    cin >> m;
    cin.ignore();
 
    for (int j=0; j<m; j++) {
        string msg;
        getline(cin, msg);       
        subject.notifyObservers(msg);
    }
 
    return 0;
}