#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <map>
#include <vector>

class Book {
public:
    std::string id;
    std::string title;
    std::string author;
    bool isBorrowed;
    std::string borrowedBy;

    Book(const std::string &id, const std::string &title, const std::string &author)
        : id(id), title(title), author(author), isBorrowed(false), borrowedBy("") {}
};

class Reader {
public:
    std::string id;
    int age;
    int borrowedCount;

    Reader(const std::string &id, int age) : id(id), age(age), borrowedCount(0) {}
};

class Library {
private:
    std::map<std::string, Book> books;
    std::map<std::string, Reader> readers;
    int seniorAgeLimit;

    static bool compareBooksById(const Book &a, const Book &b);
    static bool compareBooksByTitle(const Book &a, const Book &b);
    static bool compareBooksByAuthor(const Book &a, const Book &b);

    static bool compareReadersById(const Reader &a, const Reader &b);
    static bool compareReadersByAge(const Reader &a, const Reader &b);

public:
    Library(int seniorAgeLimit);

    void addBook(const Book &book);
    void addReader(const Reader &reader);
    void borrowBook(const std::string &readerId, const std::string &bookId);
    void returnBook(const std::string &readerId, const std::string &bookId);
    void displayBooks(const std::string &sortBy) const;
    void displayReaders(const std::string &sortBy) const;
};

#endif // LIBRARY_H
