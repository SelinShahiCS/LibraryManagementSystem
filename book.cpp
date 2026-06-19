#include <iostream>
#include <fstream>
#include "Book.h"

using namespace std;

// ===== Constructors =====

Book::Book() {
    bookID = 0;
    title = "Unknown";
    author = "Unknown";
    status = Available;
    type = Printed;
}

Book::Book(int id, string title, string author) {
    this->bookID = id;
    this->title = title;
    this->author = author;
    this->status = Available;
    this->type = Printed;
}

Book::Book(int id, string title, string author, Status status) {
    this->bookID = id;
    this->title = title;
    this->author = author;
    this->status = status;
    this->type = Printed;
}

Book::~Book() {}

// ===== Getters =====

int Book::getID() const
{
    return bookID;
} 


int Book::generateBookID() {
    vector<Book> books = loadAllBooks();

    if (books.empty())
    return 1;

    return books.back().getID() + 1;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

Status Book::getStatus() const {
    return status;
}

BookType Book::getType() const {
    return type;
}


//====================search===========
bool Book::searchBookByTitle(string title)
{
    vector<Book> books = loadAllBooks();

    bool found = false;

    for(auto &b : books)
    {
        if(b.getTitle() == title)
        {
            b.showInfo();
            found = true;
        }
    }

    return found;
}


// ==========Search by author
bool Book::searchBookByAuthor(string author)
{
    vector<Book> books = loadAllBooks();

    bool found = false;

    for(auto &b : books)
    {
        if(b.getAuthor() == author)
        {
            b.showInfo();
            found = true;
        }
    }

    return found;
}

// ===== Setters ====================

void Book::setTitle(string title) {
    if (!title.empty())
        this->title = title;
}

void Book::setAuthor(string author) {
    if (!author.empty())
        this->author = author;
}

void Book::setStatus(Status status) {
    this->status = status;
}

void Book::setType(BookType type) {
    this->type = type;
}

// ===== Show Info =================

void Book::showInfo() const {
    cout << "ID: " << bookID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;

    cout << "Status: ";
    if (status == Available) cout << "Available";
    else if (status == Borrowed) cout << "Borrowed";
    else if (status == Lost) cout << "Lost";
    else cout << "Damaged";
    cout << endl;

    cout << "Type: ";
    if (type == Printed) cout << "Printed Book";
    else if (type == Audio) cout << "Audio Book";
    else cout << "Electronic Book";
    cout << endl;

    cout << "================================\n";
}

// ===== Save Book =========================

void Book::saveBook() {
    ofstream file("books.txt", ios::app);

    file << bookID << "|"
         << title << "|"
         << author << "|"
         << status << "|"
         << type << endl;

    file.close();
}

// ===== Load All Books ===================

vector<Book> Book::loadAllBooks() {

    vector<Book> books;
    ifstream file("books.txt");

    int id;
    string title, author;
    int statusInt, typeInt;

    while (file >> id) {
        file.ignore();

        getline(file, title, '|');
        getline(file, author, '|');

        file >> statusInt;
        file.ignore();

        file >> typeInt;
        file.ignore();

        Book b(id, title, author, static_cast<Status>(statusInt));
        b.setType(static_cast<BookType>(typeInt));
        books.push_back(b);
    }

    file.close();
    return books;
}

// ===== Borrow Book ===================

bool Book::borrowBook(int id) {

    vector<Book> books = loadAllBooks();
    bool found = false;

    for (auto &b : books) {
        if (b.getID() == id && b.getStatus() == Available) {
            b.setStatus(Borrowed);
            found = true;
            break;
        }
    }

    if (!found) return false;

    ofstream file("books.txt");

    for (auto &b : books) {
        file << b.getID() << "|"
             << b.getTitle() << "|"
             << b.getAuthor() << "|"
             << b.getStatus() << "|"
             << b.getType() << endl;
    }

    file.close();
    return true;
}

// ===== Return Book =================

bool Book::returnBook(int id) {

    vector<Book> books = loadAllBooks();
    bool found = false;

    for (auto &b : books) {
        if (b.getID() == id && b.getStatus() == Borrowed) {
            b.setStatus(Available);
            found = true;
            break;
        }
    }

    if (!found) return false;

    ofstream file("books.txt");

    for (auto &b : books) {
        file << b.getID() << "|"
             << b.getTitle() << "|"
             << b.getAuthor() << "|"
             << b.getStatus() << "|"
             << b.getType() << endl;
    }

    file.close();
    return true;
}


void displayBook(Book b){
    cout << "ID: " << b.bookID << endl;
    cout << "Title: " << b.title << endl;
    cout << "Author: " << b.author << endl;
    cout << "Status: " << b.status << endl;
}

// ===== Delete==================

bool Book::deleteBook(int id) {

    vector<Book> books = loadAllBooks();
    vector<Book> updated;

    bool found = false;

    for (auto &b : books) {
        if (b.getID() == id) {
            found = true;
            continue;
        }
        updated.push_back(b);
    }

    if (!found) return false;

    ofstream file("books.txt");

    for (auto &b : updated) {
        file << b.getID() << "|"
             << b.getTitle() << "|"
             << b.getAuthor() << "|"
             << b.getStatus() << "|"
             << b.getType() << endl;
    }

    file.close();
    return true;
}