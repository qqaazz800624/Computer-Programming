#include "library.h"
#include <iostream>
#include <algorithm>

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

// Compare books by ID
bool Library::compareBooksById(const Book &a, const Book &b) {
    return a.id < b.id;
}

// Compare books by title
bool Library::compareBooksByTitle(const Book &a, const Book &b) {
    return a.title < b.title;
}

// Compare books by author
bool Library::compareBooksByAuthor(const Book &a, const Book &b) {
    return a.author < b.author;
}

// Display books
void Library::displayBooks(const std::string &sortBy) const {
    std::vector<Book> bookList;
    for (std::map<std::string, Book>::const_iterator it = books.begin(); it != books.end(); ++it) {
        bookList.push_back(it->second);
    }

    if (sortBy == "id") {
        std::sort(bookList.begin(), bookList.end(), compareBooksById);
    } else if (sortBy == "title") {
        std::sort(bookList.begin(), bookList.end(), compareBooksByTitle);
    } else if (sortBy == "author") {
        std::sort(bookList.begin(), bookList.end(), compareBooksByAuthor);
    }

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

// Compare readers by ID
bool Library::compareReadersById(const Reader &a, const Reader &b) {
    return a.id < b.id;
}

// Compare readers by age
bool Library::compareReadersByAge(const Reader &a, const Reader &b) {
    return a.age < b.age;
}

// Display readers
void Library::displayReaders(const std::string &sortBy) const {
    std::vector<Reader> readerList;
    for (std::map<std::string, Reader>::const_iterator it = readers.begin(); it != readers.end(); ++it) {
        readerList.push_back(it->second);
    }

    if (sortBy == "id") {
        std::sort(readerList.begin(), readerList.end(), compareReadersById);
    } else if (sortBy == "age") {
        std::sort(readerList.begin(), readerList.end(), compareReadersByAge);
    }

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
