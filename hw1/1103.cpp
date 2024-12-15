#include <iostream>

using namespace std;

int main(){
    int money;
    string unit[] = {"", "拾", "佰", "仟", "萬"};
    string num[] = {"零", "壹", "貳", "參", "肆", "伍", "陸", "柒", "捌", "玖"};

    cin >> money;
    if (money < 1 || money > 99999) {
        cout << "out of range" << endl;
        return 0;
    }

    int digits[5];
    int i;
    for (i = 0; i < 5; i++) {
        digits[i] = money % 10;
        money /= 10;
    }

    int zero_flag = 0;
    int printed = 0;

    for (i=4; i >= 0; i--){
        if(digits[i] != 0){
            if(zero_flag){
                cout << num[0];
                zero_flag = 0;
            }
            cout << num[digits[i]] << unit[i];
            printed = 1;
        } else if (printed){
            zero_flag = 1;
        }
    }
    cout << "元整" << endl;

    return 0;
}