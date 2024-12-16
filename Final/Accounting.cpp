#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include "Accounting.h"
using namespace std;


string custom_to_string(long long value) {
    ostringstream oss;
    oss << value;
    return oss.str();
}

string formatAmount(long long amount) {
    string result = custom_to_string(amount);
    int n = result.size();

    for (int i = n - 3; i > 0; i -= 3) {
        result.insert(i, ",");
    }
    return result;
}


void Accounting::calculateCost(Accounting R, Accounting G) {
    Code = 5000;  
    Title = "營業成本";
    Amount = R.Amount - G.Amount;  
    calculateRate(R);              
}

void Accounting::calculateRate(Accounting R) {
    Rate = round((double)Amount / R.Amount * 100);
}


void Accounting::ShowInfo() {
    
    cout << Code << "\t" << Title << "\t" 
         << formatAmount(Amount) << "\t"  
         << Rate << "%" << endl;
}