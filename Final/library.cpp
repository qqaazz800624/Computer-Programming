#include "library.h"
#include <iostream>
#include <algorithm>
#include <vector>

// Constructor
Library::Library(int seniorAgeLimit) : seniorAgeLimit(seniorAgeLimit) {}

// Add a book
void Library::addBook(const Book &book) {
    books[book.id] = book;
}

// Add a reader
void Library::addReader(const Reader &reader) {
    readers[reader.id] = reader;
}

// Borrow a book
void Library::borrowBook(const std::string &readerId, const std::string &bookId) {
    if (readers.find(readerId) == readers.end() || books.find(bookId) == books.end()) {
        std::cerr << readerId << " cannot borrow " << bookId << std::endl;
        return;
    }

    Reader &reader = readers[readerId];
    Book &book = books[bookId];

    int maxBorrowLimit = reader.age >= seniorAgeLimit ? 5 : 2;

    if (book.isBorrowed || reader.borrowedCount >= maxBorrowLimit) {
        std::cerr << readerId << " cannot borrow " << bookId << std::endl;
        return;
    }

    book.isBorrowed = true;
    book.borrowedBy = readerId;
    reader.borrowedCount++;
    std::cout << readerId << " successfully borrowed " << bookId << std::endl;
}

// Return a book
void Library::returnBook(const std::string &readerId, const std::string &bookId) {
    if (readers.find(readerId) == readers.end() || books.find(bookId) == books.end()) {
        std::cerr << readerId << " cannot return " << bookId << std::endl;
        return;
    }

    Reader &reader = readers[readerId];
    Book &book = books[bookId];

    if (!book.isBorrowed || book.borrowedBy != readerId) {
        std::cerr << readerId << " cannot return " << bookId << std::endl;
        return;
    }

    book.isBorrowed = false;
    book.borrowedBy = "";
    reader.borrowedCount--;
    std::cout << readerId << " successfully returned " << bookId << std::endl;
}

// Helper function for sorting books
bool Library::compareBooks(const Book &a, const Book &b, const std::string &sortBy) {
    if (sortBy == "id") return a.id < b.id;
    if (sortBy == "title") return a.title < b.title;
    if (sortBy == "author") return a.author < b.author;
    return false;
}

// Display books sorted by specified field
void Library::displayBooks(const std::string &sortBy) const {
    std::vector<Book> bookList;
    for (const auto &entry : books) {
        bookList.push_back(entry.second);
    }

    std::sort(bookList.begin(), bookList.end(), [&](const Book &a, const Book &b) {
        return compareBooks(a, b, sortBy);
    });

    std::cout << "=====" << std::endl;
    for (size_t i = 0; i < bookList.size(); ++i) {
        const Book &book = bookList[i];
        std::cout << "Book ID: " << book.id << std::endl;
        std::cout << "Title: " << book.title << std::endl;
        std::cout << "Author: " << book.author << std::endl;
        if (book.isBorrowed) {
            std::cout << "Borrowed: Yes, by " << book.borrowedBy << std::endl;
        } else {
            std::cout << "Borrowed: No" << std::endl;
        }
        if (i != bookList.size() - 1) {
            std::cout << "---" << std::endl;
        }
    }
    std::cout << "=====" << std::endl;
}

// Helper function for sorting readers
bool Library::compareReaders(const Reader &a, const Reader &b, const std::string &sortBy) {
    if (sortBy == "id") return a.id < b.id;
    if (sortBy == "age") return a.age < b.age;
    return false;
}

// Display readers sorted by specified field
void Library::displayReaders(const std::string &sortBy) const {
    std::vector<Reader> readerList;
    for (const auto &entry : readers) {
        readerList.push_back(entry.second);
    }

    std::sort(readerList.begin(), readerList.end(), [&](const Reader &a, const Reader &b) {
        return compareReaders(a, b, sortBy);
    });

    std::cout << "=====" << std::endl;
    for (size_t i = 0; i < readerList.size(); ++i) {
        const Reader &reader = readerList[i];
        std::cout << "Reader ID: " << reader.id << std::endl;
        std::cout << "Age: " << reader.age << std::endl;
        std::cout << "Borrowed: [" << reader.borrowedCount << "]" << std::endl;
        if (i != readerList.size() - 1) {
            std::cout << "---" << std::endl;
        }
    }
    std::cout << "=====" << std::endl;
}
