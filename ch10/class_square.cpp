#include <iostream>

using namespace std;

class Square {
    public:
        int len;

        int area(){
            return len*len;
        }
};

int main(){

    Square s1, s2;
    s1.len=10;
    s2.len=20;

    cout << "len: " << s1.len << ", area: " << s1.area() << endl;
    cout << "len: " << s2.len << ", area: " << s2.area() << endl;
    
    return 0;
}