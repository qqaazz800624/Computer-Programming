#include <iostream>
#include <string>
#include "library.h"
using namespace std;
 
int main() {
    string command; // 指令字串
    int seniorAge; // 敬老年齡界限
 
    // 以下是「接收輸入指令」用的變數
    string readerId;
    int readerAge;
    string bookId, bookTitle, bookAuthor;
    string sortBy;
 
    // 讀取敬老年齡界限
    cin >> seniorAge;
    // 建立圖書館借閱管理系統
    Library lib(seniorAge);
 
    // 處理指令
    while (cin >> command) {
        // 新增借閱者：add_reader <借閱證號> <借閱者年齡>
        if (command == "add_reader") {
            cin >> readerId >> readerAge;
            lib.addReader(Reader(readerId, readerAge));
 
        // 新增書籍：add_book <書號> <書名> <作者>
        } else if (command == "add_book") {
            cin >> bookId >> bookTitle >> bookAuthor;
            lib.addBook(Book(bookId, bookTitle, bookAuthor));
 
        // 借書：borrow <借閱證號> <書號>
        } else if (command == "borrow") {
            cin >> readerId >> bookId;
            lib.borrowBook(readerId, bookId);
 
        // 還書：return <借閱證號> <書號>
        } else if (command == "return") {
            cin >> readerId >> bookId;
            lib.returnBook(readerId, bookId);
 
        // 顯示館藏書籍資訊：list_book <排序依據>
        } else if (command == "list_book") {
            cin >> sortBy;
            lib.displayBooks(sortBy);
 
        // 顯示借閱者資訊：list_reader <排序依據>
        } else if (command == "list_reader") {
            cin >> sortBy;
            lib.displayReaders(sortBy);
 
        // 結束程式：q
        } else if (command == "q") {
            break;
        }
    }
 
    return 0;
}