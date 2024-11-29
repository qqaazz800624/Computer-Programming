#include "3210_account.h"
#include <iostream>
 
using namespace std;
 
// Account::Account(int initCash) : investmentCount(0), cash(initCash), investments(new Investment[50]())
// {}

Account::Account(int initCash){
   cash = initCash;
   investmentCount = 0;
   investments = new Investment[50]();
}
 
Account::~Account() throw(){
    delete [] this->investments;
}
 
void Account::buy(Investment *datalist, size_t dataLength, int index){
   // TODO: 實作買入動作
   if (index < 0 || static_cast<size_t>(index) >= dataLength){
      cout << "index out of range" << endl;
      return;
   }

   if (investmentCount >= 50){
      cout << "inventory full" << endl;
      return;
   }

   investments[investmentCount++] = datalist[index];
   cash -= datalist[index].low;
}
 
void Account::sellLast(const int currentPrice){
   // TODO: 實作賣出最近買入商品
   if (investmentCount == 0){
      cout << "no investment" << endl;
      return;
   }

   Investment lastInvestment = investments[--investmentCount];
   cash += currentPrice;
}
 
void Account::list(){
   // TODO: 實作列出投資紀錄
   if (investmentCount == 0){
      cout << "no investment" << endl;
      return;
   }

   int i;
   for (i = 0; i < investmentCount; i++){
      cout << investments[i].date << " " 
           << investments[i].low << " " 
           << investments[i].high << endl;
   }
}
 
int Account::getCash(){
    return this->cash;
}