#include <iostream>
#include <cmath> // for std::pow

using namespace std;

bool isArmstrong(int num) {
    int sum = 0;
    int originalNum = num;
    int digit_len = 0;
    int digit = 0;

    while (num != 0) {
        num /= 10;
        digit_len++;
    }

    num = originalNum;
    while (num != 0) {
        digit = num % 10;
        sum += pow(digit, digit_len);
        num /= 10;
    }

    return sum == originalNum;
}

int main() {
    int n, m;
    bool found = false;

    cin >> n >> m;

    for (int i = n; i <= m; i++) {
        if (isArmstrong(i)) {
            if (found) {
                cout << " & ";
            }
            cout << i;
            found = true;
        }
    }
    if (!found) {
        cout << "none";
    }
    cout << endl;

    return 0;
}
