#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

    int A, B;
    double C;
    int sum;
    double sum2, avg, sigma;

    cin >> A >> B >> C;

    int intPartC = (int)C;
    int i;

    for (i = 1000; i >= 1; i /= 10) {
        int A_digit = (A / i) % 10;
        int B_digit = (B / i) % 10;
        int C_digit = (intPartC / i) % 10;

        sum = A_digit + B_digit + C_digit;
        avg = sum / 3.0;
        sigma = sqrt((pow(A_digit - avg, 2) + pow(B_digit - avg, 2) + pow(C_digit - avg, 2)) / 3.0);

        cout << sum << " " << fixed << setprecision(2) << avg << " " << sigma << endl;
    }

    sum2 = A + B + C;
    avg = sum2 / 3.0;
    sigma = sqrt((pow(A - avg, 2) + pow(B - avg, 2) + pow(C - avg, 2)) / 3.0);

    cout << fixed << setprecision(2) << sum2 << " " << avg << " " << sigma << endl;

    return 0;
}