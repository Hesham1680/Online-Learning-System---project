#include <iostream>
#include "User.h"
#include "Course.h"
#include "Cart.h"
#include "Wishlist.h"
#include "Utils.h"

void studentMenu(User& user, Cart& cart);
void instructorMenu(User& user);
void browseCoursesMenu(User& user, Cart& cart);
void myCourses(const User& user);
void instructorAddCourse(User& user);

int main() {
    printHeader("Online Learning System");

    bool running = true;
    while (running) {
        std::cout << "\n1. Sign Up\n";
        std::cout << "2. Login\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        int choice = getValidInt(0, 2);

        if (choice == 1) {
            signUp();
        } else if (choice == 2) {
            User* user = login();
            if (user != nullptr) {
                Cart cart;
                if (user->role == UserRole::STUDENT) {
                    studentMenu(*user, cart);
                } else {
                    instructorMenu(*user);
                }
            }
        } else {
            running = false;
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}

void studentMenu(User& user, Cart& cart) {
    bool loggedIn = true;
    while (loggedIn) {
        printHeader("Student Menu - " + user.username);
        std::cout << "1. Browse Courses\n";
        std::cout << "2. View Cart\n";
        std::cout << "3. Checkout\n";
        std::cout << "4. My Courses\n";
        std::cout << "5. My Wishlist\n";
        std::cout << "0. Logout\n";
        std::cout << "Choice: ";
        int choice = getValidInt(0, 5);

        if (choice == 1) {
            browseCoursesMenu(user, cart);
        } else if (choice == 2) {
            cart.display();
        } else if (choice == 3) {
            checkout(cart, user);
        } else if (choice == 4) {
            myCourses(user);
        } else if (choice == 5) {
            displayWishlist(user);
            if (!user.wishlist.empty()) {
                std::cout << "\nRemove a course from wishlist? Enter course ID (0 to skip): ";
                int id = getValidInt(0, 9999);
                if (id != 0) {
                    removeFromWishlist(user, id);
                }
            }
        } else {
            loggedIn = false;
        }
    }
}

void browseCoursesMenu(User& user, Cart& cart) {
    displayCourseList(false);
    std::vector<Course>& courses = getCourseList();

    std::cout << "\nEnter course ID to view details (0 to go back): ";
    int id = getValidInt(0, 9999);
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

    displayCourseDetail(*selected, false);

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
    int action = getValidInt(0, 2);

    if (action == 1) {
        cart.addItem(*selected);
    } else if (action == 2) {
        addToWishlist(user, *selected);
    }
}

void myCourses(const User& user) {
    printHeader("My Courses");
    if (user.purchasedCourses.empty()) {
        std::cout << "You have not purchased any courses yet.\n";
        return;
    }
    for (const Course& c : user.purchasedCourses) {
        std::cout << "[" << c.id << "] " << c.name
                  << " - " << c.hours << " hours\n";
    }
}

void instructorMenu(User& user) {
    bool loggedIn = true;
    while (loggedIn) {
        printHeader("Instructor Menu - " + user.username);
        std::cout << "1. Add New Course\n";
        std::cout << "2. View All Courses\n";
        std::cout << "0. Logout\n";
        std::cout << "Choice: ";
        int choice = getValidInt(0, 2);

        if (choice == 1) {
            instructorAddCourse(user);
        } else if (choice == 2) {
            displayCourseList(false);
        } else {
            loggedIn = false;
        }
    }
}

void instructorAddCourse(User& user) {
    printHeader("Add New Course");

    std::string name = getValidString("Course name: ");
    std::string description = getValidString("Description: ");
    std::string category = getValidString("Category: ");
    std::string difficulty = getValidString("Difficulty (Beginner/Intermediate/Advanced): ");

    std::cout << "Hours to complete: ";
    int hours = getValidInt(1, 500);

    std::cout << "Price ($): ";
    double price = 0.0;
    std::cin >> price;
    std::cin.ignore();

    std::cout << "Certification available? (1 = Yes, 0 = No): ";
    int cert = getValidInt(0, 1);

    std::vector<Course>& courses = getCourseList();
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

    addCourse(newCourse);
    std::cout << "Course \"" << name << "\" added successfully.\n";
}
