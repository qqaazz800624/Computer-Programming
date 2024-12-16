#include <iostream>
#include <string>
#include <fstream>
 
#include "3210_investment.h"
#include "3210_account.h"
 
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
 
    char command;
    cin >> command;
    while (command != 'q') {
        if (command == 'b') {
            int index = 0;
            cin >> index;
            account.buy(dataList, dataLength, index);
        } else if (command == 's'){
            account.sellLast(dataList[dataLength-1].high);
        } else if (command == 'l'){
            account.list();
        } else if (command == 'c'){
            cout << account.getCash() << endl;
        }
 
        cin >> command;
    }
 
    delete [] dataList;
 
    return 0;
}