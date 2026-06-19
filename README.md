# Library Management System (C++)

A console-based Library Management System built in C++, demonstrating core Object-Oriented Programming principles including **inheritance** and **runtime polymorphism**.

## Features

### Admin
- Secure login / logout
- Add, delete, and search books (by title or author)
- View all books and detailed book information
- Book type selection (Printed / Audio / Electronic)

### User
- Sign up and login
- Browse all available books
- Borrow and return books

## OOP Concepts Demonstrated

- **Inheritance** — `Admin` and `userInfo` both inherit from a common base class `Person`.
- **Polymorphism** — `Person` declares a virtual function `showRole()`, which is overridden differently by `Admin` and `userInfo`. The correct version is resolved at **runtime** through a `Person*` base-class pointer, demonstrating dynamic dispatch.
- **Encapsulation** — private/protected data members are accessed only through public methods.
- **File-based persistence** — book and user records are stored in plain text files (`books.txt`, `users.txt`).

## Tech Stack

- **Language:** C++ (no external libraries)
- **Compiler:** g++
- **Storage:** plain text files

## Project Structure

```
.
├── main.cpp              # Entry point and menu system
├── person.h              # Base class (Person) — inheritance & polymorphism root
├── admin.h / admin.cpp    # Admin class (extends Person)
├── user.h / user.cpp      # userInfo class (extends Person)
├── Book.h / Book.cpp      # Book class and file-based book management
```

## How to Build & Run

**Linux / macOS:**
```bash
g++ -o library main.cpp admin.cpp Book.cpp user.cpp
./library
```

**Windows:**
```bash
g++ -o library.exe main.cpp admin.cpp Book.cpp user.cpp
library.exe
```

## Usage

On launch, choose one of:

1. **Admin** — log in with the default credentials (`admin` / `1234`) to manage the book catalog.
2. **User** — sign up, then log in to browse, borrow, and return books.

## Future Improvements

- Replace plain-text storage with a real database (SQLite / MySQL)
- Extend `Book` into true polymorphic subclasses (`PrintedBook`, `AudioBook`, `EBook`) with type-specific behavior
- Add stronger input validation and password handling

## Author

Selin — 
