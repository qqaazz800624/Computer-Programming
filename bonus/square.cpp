#include <iostream>
#include "square.h"

using namespace std;

// 預設建構式：將邊長設為 0
Square::Square() : len(0) {}

// 重載建構式：檢查邊長是否合法，若不合法則設為 1
Square::Square(int n)
{
    if (n < 1) {
        cout << "len setting error" << endl;
        len = 1; // 設為 1
    } else {
        len = n;
    }
}

// 計算面積 (len * len)
int Square::area()
{
    return len * len;
}

// 設定邊長，並檢查是否合法
void Square::setLen(int n)
{
    if (n < 1) {
        cout << "len setting error" << endl;
        len = 1;
    } else {
        len = n;
    }
}

// 取得邊長
int Square::getLen()
{
    return len;
}
