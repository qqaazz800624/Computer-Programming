#include <iostream>
#include <string>
#include <fstream>
 
#include "investment.h"
#include "account.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
    ifstream file("gold_price.csv");
    Investment *dataList = new Investment[100]();
    Account account(10000);
 
    size_t dataLength = 0;
    while (!file.eof()) {
        string line;
        file >> line;
        if (line.length() == 0){
            continue;
        }
 
        Investment investment(line);
        dataList[dataLength++] = investment;
    }
    file.close();
 
    char command = 0;
    cin >> command;
    while (command != 'q') {
        if (command == 'b') {
            int index = 0;
            cin >> index;
            // 買進位於資料index
            account.buy(dataList, dataLength, index);
        } else if (command == 's'){
            // 賣出最新一日最高價
            account.sellLast(dataList[dataLength-1].high);
        } else if (command == 'l'){
            // 列出所有庫存，格式：(時間)(空格)(當日最低價)(空格)(當日最高價)(換行)
            account.list();
        } else if (command == 'c'){
            // 印出目前現金(整數)
            cout << account.getCash() << endl;
        }
 
        cin >> command;
    }
 
    delete [] dataList;
 
    return 0;
}