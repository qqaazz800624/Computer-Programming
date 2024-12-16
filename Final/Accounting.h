#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include <string>
using namespace std;

class Accounting {
public:
    int Code;            
    string Title;        
    long long Amount;    
    int Rate;            

    void calculateCost(Accounting R, Accounting G);  
    void calculateRate(Accounting R);               
    void ShowInfo();                                
};

#endif