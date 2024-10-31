#include <iostream>

using namespace std;

class Person {
    public:
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

    Person p1, p2;
    p1.input();  // p1.height = 0 is not allowed
    p1.ouput();
    p2.input();
    p2.ouput();
    
    return 0;
}