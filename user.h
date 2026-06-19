#ifndef USER_H
#define USER_H

#include <string>
#include "person.h"

class userInfo : public Person {

private:
    bool isLoggedIn;

public:
    userInfo();

    void signUp();
    void logIn();
    void logOut();

    bool isUserLoggedIn() const;

    void showRole() const override;
};

#endif