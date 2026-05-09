/* 
* Copyright 2026 Cairo University - SCS253 - Online Learning System
* Defines the User struct and declares signup/login functions.
*/ 

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Course.h"

enum class UserRole {
    STUDENT,
    INSTRUCTOR
};

struct User {
    std::string username;
    std::string password;
    UserRole role;
    std::vector<Course> purchasedCourses;
    std::vector<Course> wishlist;
};

std::vector<User>& getUserList();
bool signUp();
User* login();

#endif
