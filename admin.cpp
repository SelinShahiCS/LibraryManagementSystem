#include <iostream>
#include "admin.h"
#include "Book.h"

using namespace std;

// ===== Constructor =====

Admin::Admin(string id, string username, string password)
    : Person(username, password), adminID(id), adminUsername(username), adminPassword(password), isLoggedIn(false) {}

// ===== Login =====

bool Admin::login(string username, string password) {

    if(isLoggedIn){
        cout << "Admin is already logged in" << endl;
        return true;
    }

    if (username == adminUsername && password == adminPassword) {
        isLoggedIn = true;
        cout << "Admin logged in successfully!\n";
        return true;
    }

    cout << "Wrong username or password!\n";
    return false;
}

// ===== Logout =====

void Admin::logout() {
    if(!isLoggedIn){
        cout << "Admin is not logged in!!";
        return;
    }
    isLoggedIn = false;
    cout << "Admin logged out successfully.";
}

// ===== Check Login =====

bool Admin::isAdminLoggedIn() const {
    return isLoggedIn;
}

// ===== Add Book =======================

void Admin::addBook() {

    if (!isLoggedIn) {
        cout << "You must login first!\n";
        return;
    }

    int id = Book::generateBookID();
    string title, author;

    cout << "Book ID: " << id << endl;

    cin.ignore();

    cout << "Enter title: ";
    getline(cin, title);

    cout << "Enter author: ";
    getline(cin, author);

    cout << "Select Book Type:\n";
    cout << "1. Printed\n";
    cout << "2. Audio\n";
    cout << "3. Electronic\n";
    cout << "Choice: ";

    int typeChoice;
    cin >> typeChoice;

    BookType type;
    switch (typeChoice) {
        case 1: type = Printed; break;
        case 2: type = Audio; break;
        case 3: type = Electronic; break;
        default:
            cout << "Invalid choice, defaulting to Printed.\n";
            type = Printed;
    }

    Book newBook(id , title, author);
    newBook.setType(type);
    newBook.saveBook();

    cout << "Book added successfully!\n";
}

// =============== Delete Book ===========

void Admin::deleteBook() {

    if (!isLoggedIn) {
        cout << "You must login first!\n";
        return;
    }

    int id;

    cout << "Enter Book ID to delete: ";
    cin >> id;

    if (Book::deleteBook(id))
        cout << "Book deleted successfully!\n";
    else
        cout << "Book not found!\n";
}

// ============ Show All Books =======================

void Admin::showAllBooks() {

    if (!isLoggedIn) {
        cout << "You must login first!\n";
        return;
    }

    vector<Book> books = Book::loadAllBooks();

    if (books.empty()) {
        cout << "No books found!\n";
        return;
    }

    for (auto &b : books) {
        b.showInfo();
    }
}

//======================Search Book==============

void Admin::searchBookByTitle()
{
    if(!isLoggedIn)
    {
        cout << "You must login first!\n";
        return;
    }

    cin.ignore();

    string title;

    cout << "Enter book title: ";
    getline(cin, title);

    if(!Book::searchBookByTitle(title))
    {
        cout << "Book not found!\n";
    }
}

void Admin::searchBookByAuthor()
{
    if (!isLoggedIn)
    {
        cout << "You must login first!\n";
        return;
    }

    cin.ignore();

    string author;

    cout << "Enter author name: ";
    getline(cin, author);

    if (!Book::searchBookByAuthor(author))
    {
        cout << "No books found!\n";
    }
}


void Admin::ShowBookPrivateInfo(){

    if(!isLoggedIn){
        cout << "You must ligin first";
        return;
    }

    Book b(100 , "Book A" , "Author B");
    displayBook(b);

    cout <<"Private Book Information" << endl;
    cout << "ID: " << b.bookID <<endl;
    cout << "Title: " << b.title <<endl;
    cout << "Author: " << b.author <<endl;
    cout << "Status: " << b.status <<endl;
}





// ===== Show Role (Polymorphism) ======================

void Admin::showRole() const {
    cout << "Role: Admin" << endl;
}




// ===== Users =====

void Admin::showAllUsers() {
    cout << "User system not implemented yet!\n";
}

void Admin::deleteUser() {
    cout << "User system not implemented yet!\n";
}