#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        void input(){
            cin >> name;
            cin >> height;
            cin >> weight;
        }
        void output(){
            cout << "Name: " << name << endl;
            cout << "Height: " << height << " cm" << endl;
            cout << "Weight: " << weight << " kg" << endl;
        }
        string name;
        int height;
        int weight;
};

int main(){

    Person p1;
    Person p2;

    p1.input();
    p1.output();
    p2.input();
    p2.output();
    
    return 0;
}