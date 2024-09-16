#ifndef SQUARE_H
#define SQUARE_H

class Square
{
private:
    int len; // 邊長，屬性設為私有，物件實體無法直接存取

public:
    // 建構式: 預設將邊長設為 0
    Square();

    // 重載建構式: 若輸入不正確，顯示錯誤訊息並設為 1
    Square(int n);

    // 計算面積
    int area();

    // 設定邊長，需判斷邊長是否正確
    void setLen(int n);

    // 取得邊長
    int getLen();
};

#endif // SQUARE_H
