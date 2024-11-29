#include "3210_investment.h"
#include <iostream>
#include <sstream>
 
// Investment::Investment(): date(""), high(0), low(0){
// }

Investment::Investment(){
    date = "";
    high = 0;
    low = 0;
}
 
Investment::Investment(string data){
    // TODO: 需實做建構子
    stringstream ss(data);
    string lowStr, highStr;
    
    getline(ss, date, ',');
    getline(ss, lowStr, ',');
    getline(ss, highStr, ',');

    stringstream lowStream(lowStr);
    lowStream >> low;

    stringstream highStream(highStr);
    highStream >> high;
}