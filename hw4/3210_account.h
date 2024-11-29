#ifndef account_hpp
#define account_hpp
 
#include "investment.h"
class Account {
 
private:
    int cash;
    int investmentCount;
    Investment *investments;
 
public:
    Account(int initCash);
    ~Account() throw();
    void buy(Investment *datalist, size_t dataLength, int index);
    void sellLast(const int currentPrice);
    void list();
    int getCash();
};
 
#endif /* account_hpp */