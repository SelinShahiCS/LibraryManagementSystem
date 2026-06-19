#include <iostream>
#include <fstream>
#include <vector>
#include "user.h"

using namespace std;

// ===== Constructor =====

userInfo::userInfo() : Person() {
    isLoggedIn = false;
}


// ===== Sign Up =====

void userInfo::signUp() {

    string u, p;

    cout << "Enter username: ";
    cin >> u;

    cout << "Enter password: ";
    cin >> p;

    ofstream file("users.txt", ios::app);

    file << u << "|" << p << endl;

    file.close();

    cout << "User registered successfully!\n";
}

// ===== Login =====

void userInfo::logIn() {

    if(isLoggedIn){
        cout <<"User is logged in already";
        return;
    }

    string u, p;

    cout << "Enter username: ";
    cin >> u;

    cout << "Enter password: ";
    cin >> p;

    ifstream file("users.txt");

    string line;
    bool found = false;

    while (getline(file, line)) {

        int pos = line.find('|');

        string fileUser = line.substr(0, pos);
        string filePass = line.substr(pos + 1);

        if (fileUser == u && filePass == p) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        isLoggedIn = true;
        username = u;
        cout << "Login successful!\n";
    } else {
        cout << "Invalid username or password!\n";
    }
}

// ===== Logout ==========

void userInfo::logOut() {
    if(!isLoggedIn){
        cout << "User is not logged in!!!";
        return;
    }
    isLoggedIn = false;
    cout << "Logged out successfully.";
}



// ===== Show Role (Polymorphism) ====================
void userInfo::showRole() const {
    cout << "Role: User" << endl;
}


// =========== Check =====

bool userInfo::isUserLoggedIn() const {
    return isLoggedIn;
}