/* * Copyright 2026 Cairo University - SCS253 - Online Learning System
   * Entry point. Manages the main menu, student menu, and instructor menu. */ 

#include <iostream>
#include "User.h"
#include "Course.h"
#include "Cart.h"
#include "Wishlist.h"
#include "Utils.h"

void StudentMenu(User& user, Cart& cart);
void InstructorMenu(User& user);
void BrowseCoursesMenu(User& user, Cart& cart);
void MyCourses(const User& user);
void InstructorAddCourse(User& user);

int main() {
    PrintHeader("Online Learning System");

    bool running = true;
    while (running) {
        std::cout << "\n1. Sign Up\n";
        std::cout << "2. Login\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        int choice = GetValidInt(0, 2);

        if (choice == 1) {
            SignUp();
        } else if (choice == 2) {
            User* user = Login();
            if (user != nullptr) {
                Cart cart;
                if (user->role == UserRole::STUDENT) {
                    StudentMenu(*user, cart);
                } else {
                    InstructorMenu(*user);
                }
            }
        } else {
            running = false;
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}

void StudentMenu(User& user, Cart& cart) {
    bool loggedIn = true;
    while (loggedIn) {
        PrintHeader("Student Menu - " + user.username);
        std::cout << "1. Browse Courses\n";
        std::cout << "2. View Cart\n";
        std::cout << "3. Checkout\n";
        std::cout << "4. My Courses\n";
        std::cout << "5. My Wishlist\n";
        std::cout << "0. Logout\n";
        std::cout << "Choice: ";
        int choice = GetValidInt(0, 5);

        if (choice == 1) {
            BrowseCoursesMenu(user, cart);
        } else if (choice == 2) {
            cart.Display();
        } else if (choice == 3) {
            Checkout(cart, user);
        } else if (choice == 4) {
            MyCourses(user);
        } else if (choice == 5) {
            DisplayWishlist(user);
            if (!user.wishlist.empty()) {
                std::cout << "\nRemove a course from wishlist? Enter course ID (0 to skip): ";
                int id = GetValidInt(0, 9999);
                if (id != 0) {
                    RemoveFromWishlist(user, id);
                }
            }
        } else {
            loggedIn = false;
        }
    }
}

void BrowseCoursesMenu(User& user, Cart& cart) {
    DisplayCourseList(false);
    std::vector<Course>& courses = GetCourseList();

    std::cout << "\nEnter course ID to view details (0 to go back): ";
    int id = GetValidInt(0, 9999);
    if (id == 0) {
        return;
    }

    Course* selected = nullptr;
    for (Course& c : courses) {
        if (c.id == id) {
            selected = &c;
            break;
        }
    }

    if (selected == nullptr) {
        std::cout << "Course not found.\n";
        return;
    }

    DisplayCourseDetail(*selected, false);

    bool alreadyOwned = false;
    for (const Course& owned : user.purchasedCourses) {
        if (owned.id == selected->id) {
            alreadyOwned = true;
            break;
        }
    }

    if (alreadyOwned) {
        std::cout << "You already own this course.\n";
        return;
    }

    std::cout << "\n1. Add to Cart\n";
    std::cout << "2. Add to Wishlist\n";
    std::cout << "0. Go Back\n";
    std::cout << "Choice: ";
    int action = GetValidInt(0, 2);

    if (action == 1) {
        cart.AddItem(*selected);
    } else if (action == 2) {
        AddToWishlist(user, *selected);
    }
}

void MyCourses(const User& user) {
    PrintHeader("My Courses");
    if (user.purchasedCourses.empty()) {
        std::cout << "You have not purchased any courses yet.\n";
        return;
    }
    for (const Course& c : user.purchasedCourses) {
        std::cout << "[" << c.id << "] " << c.name
                  << " - " << c.hours << " hours\n";
    }
}

void InstructorMenu(User& user) {
    bool loggedIn = true;
    while (loggedIn) {
        PrintHeader("Instructor Menu - " + user.username);
        std::cout << "1. Add New Course\n";
        std::cout << "2. View All Courses\n";
        std::cout << "0. Logout\n";
        std::cout << "Choice: ";
        int choice = GetValidInt(0, 2);

        if (choice == 1) {
            InstructorAddCourse(user);
        } else if (choice == 2) {
            DisplayCourseList(false);
        } else {
            loggedIn = false;
        }
    }
}

void InstructorAddCourse(User& user) {
    PrintHeader("Add New Course");

    std::string name = GetValidString("Course name: ");
    std::string description = GetValidString("Description: ");
    std::string category = GetValidString("Category: ");
    std::string difficulty = GetValidString("Difficulty (Beginner/Intermediate/Advanced): ");

    std::cout << "Hours to complete: ";
    int hours = GetValidInt(1, 500);

    std::cout << "Price ($): ";
    double price = 0.0;
    std::cin >> price;
    std::cin.ignore();

    std::cout << "Certification available? (1 = Yes, 0 = No): ";
    int cert = GetValidInt(0, 1);

    std::vector<Course>& courses = GetCourseList();
    int newId = static_cast<int>(courses.size()) + 1;

    Course newCourse;
    newCourse.id = newId;
    newCourse.name = name;
    newCourse.description = description;
    newCourse.category = category;
    newCourse.difficulty = difficulty;
    newCourse.hours = hours;
    newCourse.price = price;
    newCourse.hasCertification = (cert == 1);
    newCourse.instructorName = user.username;

    AddCourse(newCourse);
    std::cout << "Course \"" << name << "\" added successfully.\n";
}
