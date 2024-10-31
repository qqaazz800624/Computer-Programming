#include <iostream>

using namespace std;

class Square {
    public:
        Square(){
            len = 0;
        }

        Square(int n){
            SetLen(n);
        }
        
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

    Square s1, s2, s3;
    int n1, n2;
    cin >> n1 >> n2;
    s1.SetLen(n1);
    s2.SetLen(n2);
    
    cout << "Area = " << s1.area() << " cm^2" << endl;
    cout << "Area = " << s2.area() << " cm^2" << endl;
    cout << "Area = " << s3.area() << " cm^2" << endl;

    // cout << "len: " << s1.getLen() << ", area: " << s1.area() << endl;
    // cout << "len: " << s2.getLen() << ", area: " << s2.area() << endl;
    // cout << "len: " << s3.getLen() << ", area: " << s3.area() << endl;
    
    return 0;
}