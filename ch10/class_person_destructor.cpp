#include <iostream>

using namespace std;

class Person {
    public:
        Person(){
            name = "No name";
            height = 0;
            weight = 0;
        };

        ~Person(){
            cout << "ByeBye" << endl;
        };

        Person(string n, int h, int w){
            name = n;
            height = h;
            weight = w;
        };
        
        void input(){
            cin >> name;
            cin >> height;
            cin >> weight;
        };

        void ouput(){
            cout << "Name: " << name << endl;
            cout << "Height: " << height << " cm" << endl;
            cout << "Weight: " << weight << " kg" << endl;
        };

    private:
        string name;
        int height;
        int weight;
};

int main(){

    Person p1;
    p1.ouput();
    
    return 0;
}