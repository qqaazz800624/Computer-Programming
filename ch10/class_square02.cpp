#include <iostream>

using namespace std;

class Square {
    public:
        int area(){
            return len*len;
        }
        void SetLen(int n){
            if (n < 0){
                cout << "Error: negative length" << endl;
                len = 0;
                return;
            }
            len = n;
        }
        int getLen(){
            return len;
        }

    private:
        int len;
};

int main(){

    Square s1, s2;
    s1.SetLen(10);
    s2.SetLen(20);

    cout << "len: " << s1.getLen() << ", area: " << s1.area() << endl;
    cout << "len: " << s2.getLen() << ", area: " << s2.area() << endl;
    
    return 0;
}