#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Admin;

enum Status {
    Available,
    Borrowed,
    Lost,
    Damaged
};

enum BookType{
    Printed,
    Audio,
    Electronic
};

class Book {

friend class Admin;
friend void displayBook(Book b);

private:
    int bookID;
    std::string title;
    std::string author;
    Status status;
    BookType type;
  
public:

    Book();
    Book(int id, std::string title, std::string author);
    Book(int id, std::string title, std::string author, Status status);

    ~Book();

    // getters
    int getID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    Status getStatus() const;
    BookType getType() const;

    // setters
    void setTitle(std::string title);
    void setAuthor(std::string author);
    void setStatus(Status status);
    void setType(BookType type);

    // functions
    void showInfo() const;
    void saveBook();

    static std::vector<Book> loadAllBooks();
    static bool deleteBook(int id);

    static int generateBookID();

    static bool searchBookByTitle(std::string title);
    static bool searchBookByAuthor(std::string author);

    static bool borrowBook(int id);
    static bool returnBook(int id);
};

#endif