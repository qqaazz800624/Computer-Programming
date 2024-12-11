#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(){
    string input;
    size_t i;
    int bit;
    
    while(1){
        if(!getline(cin, input)){
            break;
        }

        if (input == "-1") {
            break;
        }

        for (i=0; i<input.length(); i++){
            unsigned char ch = input[i];

            for (bit = 6; bit >= 0; bit--){
                if (ch & (1 << bit)){
                    cout << "1";
                } else {
                    cout << "0";
                }
            }
            cout << ",";
        }
        cout << endl;
    }
}