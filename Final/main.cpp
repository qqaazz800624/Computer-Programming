#include <iostream>
#include "Accounting.h"
using namespace std;
 
int main()
{
    Accounting r, c, g;
    string title;
    int code;
    long long amount;
 
    cin >> code >> title >> amount;    
    r.Code = code;
    r.Title = title;
    r.Amount = amount;
 
    cin >> code >> title >> amount;
    g.Code = code;
    g.Title = title;
    g.Amount = amount;
 
    r.calculateRate(r);
    c.calculateCost(r, g);
    g.calculateRate(r);
 
    cout << "代碼\t項目\t金額\t%" << endl;
    r.ShowInfo();
    c.ShowInfo();
    g.ShowInfo();
 
    return 0;
}