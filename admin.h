#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "person.h"

class Admin : public Person{
    private:
        std::string adminID;
        std::string adminUsername;
        std::string adminPassword;
        bool isLoggedIn;

    public:
        Admin(std::string id, std::string username, std::string password);

        bool login(std::string username, std::string password);
        void logout();

        bool isAdminLoggedIn() const;

        void addBook();
        void deleteBook();
        void showAllBooks();

        void searchBookByTitle();
        void searchBookByAuthor();

        void ShowBookPrivateInfo();

        void showAllUsers();
        void deleteUser();

        void showRole() const override;
    };

#endif