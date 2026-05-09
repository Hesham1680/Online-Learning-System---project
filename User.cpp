// Implements user signup, login, and session management.

#include "User.h"
#include "Utils.h"
#include <iostream>
#include <algorithm>

std::vector<User>& getUserList() {
    static std::vector<User> users;
    return users;
}

bool signUp() {
    printHeader("Sign Up");
    std::string username = getValidString("Enter username: ");
    std::vector<User>& users = getUserList();

    for (const User& u : users) {
        if (u.username == username) {
            std::cout << "Username already exists. Try a different one.\n";
            return false;
        }
    }

    std::string password = getValidString("Enter password: ");

    std::cout << "Select role:\n";
    std::cout << "1. Student\n";
    std::cout << "2. Instructor\n";
    std::cout << "Choice: ";
    int roleChoice = getValidInt(1, 2);

    User newUser;
    newUser.username = username;
    newUser.password = password;
    newUser.role = (roleChoice == 1) ? UserRole::STUDENT : UserRole::INSTRUCTOR;

    users.push_back(newUser);
    std::cout << "Account created successfully. Welcome, " << username << "!\n";
    return true;
}

User* login() {
    printHeader("Login");
    std::string username = getValidString("Enter username: ");
    std::string password = getValidString("Enter password: ");

    std::vector<User>& users = getUserList();
    for (User& u : users) {
        if (u.username == username && u.password == password) {
            std::cout << "Login successful. Welcome back, " << username << "!\n";
            return &u;
        }
    }

    std::cout << "Invalid username or password.\n";
    return nullptr;
}
