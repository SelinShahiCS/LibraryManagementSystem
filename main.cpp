#include <iostream>
#include "admin.h"
#include "Book.h"
#include "user.h"
#include "person.h"

using namespace std;

int main() {

    Admin admin("1", "admin", "1234");

    userInfo user;

    int mainChoice;

    do {

        cout << "\n===== Library Management System =====\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> mainChoice;

        switch (mainChoice) {

        case 1: {

            Person* currentPerson = &admin;
            int choice;

            do {

                currentPerson->showRole();   // polymorphism: Admin::showRole()
                cout << "\n===== Admin Menu =====\n";
                cout << "1. Login\n";
                cout << "2. Add Book\n";
                cout << "3. Delete Book\n";
                cout << "4. Show All Books\n";
                cout << "5. Show book Informationn\n";
                cout << "6. Search book by title\n";
                cout << "7. Search book by author\n";
                cout << "8. Logout\n";
                cout << "9. Back to Main Menu\n";
                cout << "Choice: ";
                cin >> choice;

                switch (choice) {

                case 1: {
                    string u, p;

                    cout << "Username: ";
                    cin >> u;

                    cout << "Password: ";
                    cin >> p;

                    admin.login(u, p);
                    break;
                }

                case 2:
                    admin.addBook();
                    break;

                case 3:
                    admin.deleteBook();
                    break;

                case 4:
                    admin.showAllBooks();
                    break;

                case 5:
                    admin.ShowBookPrivateInfo();
                    break;

                case 6:
                    admin.searchBookByTitle();
                    break;


                case 7:
                    admin.searchBookByAuthor();
                    break;

                case 8:
                    admin.logout();
                    break;

                case 9:
                    cout << "Returning to Main Menu...\n";
                    break;

                default:
                    cout << "Invalid choice!\n";
                }

            } while (choice != 9);

            break;
        }

        case 2: {

            Person* currentPerson = &user;
            int userChoice;

            do{
                currentPerson->showRole();   // polymorphism: userInfo::showRole()
                cout << "===== User Menu =====" << endl;
                cout << "1. Sign Up" << endl;
                cout << "2. Login" << endl;
                cout << "3. Show all books" << endl;
                cout << "4. Borrow books" << endl;
                cout << "5. Return books" << endl;
                cout << "6. Log Out" << endl;
                cout << "7. Back to Main Menu" << endl;
                
                cout << "Choice: ";

                cin >> userChoice;

                switch (userChoice){
                    case 1:
                        user.signUp();
                        break;

                    case 2:
                        user.logIn();
                        break;

                    case 3:
                        if(!user.isUserLoggedIn()){
                            cout << "Please, login first";
                            break;
                        }

                        {
                            vector<Book> books = Book::loadAllBooks();
                            if (books.empty()) {
                                cout << "No books found";
                            }
                            else{
                                for (auto &b : books)
                                b.showInfo();
                            }
                        }
                        break;


                    case 4:
                        if (!user.isUserLoggedIn()){
                            cout << "Please, log in first" << endl;
                            break;
                        }
                        

                        int borrowedId;

                        cout << "Enter book id please: ";
                        cin >> borrowedId;

                        
                        if (Book::borrowBook(borrowedId))
                            cout << "Book borrowed successfully..." <<endl;
                        else{
                            cout << "Book is unavailable...";
                        }
                        break;
                            
                    case 5:
                        if (!user.isUserLoggedIn()){
                            cout << "Please, log in first" << endl;
                            break;
                        }
                        int returnId;

                        cout << "Enter book id: ";
                        cin >> returnId;

                        if (Book::returnBook(returnId))
                            cout << "Book returned successfully..." <<endl;
                        else{
                            cout << "Book was not borrowed already...";
                        }
                        break;


                    case 6:
                        user.logOut();
                        break;

                    case 7:
                        cout << "Returning to Main Menu";
                        break;

                    default:
                    cout << "Invalid Choice";
                }
                
            }while (userChoice != 7);

            break;
        
        }

        case 3:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (mainChoice != 3);

    return 0;
}