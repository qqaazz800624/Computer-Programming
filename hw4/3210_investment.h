#ifndef investment_hpp
#define investment_hpp
#include <string>
using namespace std;
 
class Investment {
public:
    string date;
    int high;
    int low;
    Investment();
    Investment(string data);
};
 
#endif /* investment_hpp */