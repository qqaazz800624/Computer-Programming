#include <iostream>

using namespace std;

class Square {
    public:
        
        Square(int n){
            len = n;
        }
        
        int area(){
            return len*len;
        }

        int getLen(){
            return len;
        }

        friend int compare(Square &s1, Square &s2);
        friend class Ruler;

    private:
        int len;
};

int compare(Square &s1, Square &s2){
    if (s1.len > s2.len){
        return 1;
    } else if (s1.len < s2.len){
        return -1;
    } else {
        return 0;
    }
}

class Ruler {
    public:
        Ruler(int n){
            len = n;
        }

        void compareSquare(Square &s1, Square &s2){
            if ((len < s1.len) || len < s2.len){
                cout << "Ruler is too short." << endl;
            } else if (s1.len > s2.len){
                cout << "s1 is bigger." << endl;
            } else if (s1.len < s2.len){
                cout << "s2 is bigger." << endl;
            } else {
                cout << "s1 and s2 are the same." << endl;
            }
        }

    private:
        int len;
};


int main(){

    Square s1(10), s2(20);
    Ruler r(25);

    cout << "s1:len = " << s1.getLen() << ", area = " << s1.area() << endl;
    cout << "s2:len = " << s2.getLen() << ", area = " << s2.area() << endl;
    r.compareSquare(s1, s2);

    // switch (compare(s1, s2))
    // {
    // case 1:
    //     cout << "s1 is bigger." << endl;
    //     break;
    // case 0:
    //     cout << "s1 and s2 are the same." << endl;
    //     break;
    // case -1:
    //     cout << "s2 is bigger." << endl;
    //     break;
    // }
    
    return 0;
}