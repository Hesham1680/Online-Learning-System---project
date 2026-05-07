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
