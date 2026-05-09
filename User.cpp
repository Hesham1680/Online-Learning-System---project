/* Copyright 2026 Cairo University - SCS253 - Online Learning System
   * Implements user signup, login, and session management. 
   */ 

#include "User.h"
#include "Utils.h"
#include <iostream>

std::vector<User>& GetUserList() {
    static std::vector<User> users;
    return users;
}

bool SignUp() {
    PrintHeader("Sign Up");
    std::string username = GetValidString("Enter username: ");
    std::vector<User>& users = GetUserList();

    for (const User& u : users) {
        if (u.username == username) {
            std::cout << "Username already exists. Try a different one.\n";
            return false;
        }
    }

    std::string password = GetValidString("Enter password: ");

    std::cout << "Select role:\n";
    std::cout << "1. Student\n";
    std::cout << "2. Instructor\n";
    std::cout << "Choice: ";
    int roleChoice = GetValidInt(1, 2);

    User newUser;
    newUser.username = username;
    newUser.password = password;
    newUser.role = (roleChoice == 1) ? UserRole::STUDENT : UserRole::INSTRUCTOR;

    users.push_back(newUser);
    std::cout << "Account created successfully. Welcome, " << username << "!\n";
    return true;
}

User* Login() {
    PrintHeader("Login");
    std::string username = GetValidString("Enter username: ");
    std::string password = GetValidString("Enter password: ");

    std::vector<User>& users = GetUserList();
    for (User& u : users) {
        if (u.username == username && u.password == password) {
            std::cout << "Login successful. Welcome back, " << username << "!\n";
            return &u;
        }
    }

    std::cout << "Invalid username or password.\n";
    return nullptr;
}
