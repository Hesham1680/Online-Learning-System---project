/* Copyright 2026 Cairo University - SCS253 - Online Learning System
* Implements wishlist operations: add, remove, and display. */

#include "Wishlist.h"
#include "Utils.h"
#include <iostream>
#include <algorithm>

void AddToWishlist(User& user, const Course& course) {
    if (IsInWishlist(user, course.id)) {
        std::cout << "\"" << course.name << "\" is already in your wishlist.\n";
        return;
    }
    user.wishlist.push_back(course);
    std::cout << "\"" << course.name << "\" added to wishlist.\n";
}

void RemoveFromWishlist(User& user, int courseId) {
    auto it = std::remove_if(user.wishlist.begin(), user.wishlist.end(),
        [courseId](const Course& c) { return c.id == courseId; });
    if (it != user.wishlist.end()) {
        std::cout << "\"" << it->name << "\" removed from wishlist.\n";
        user.wishlist.erase(it, user.wishlist.end());
    } else {
        std::cout << "Course not found in wishlist.\n";
    }
}

void DisplayWishlist(const User& user) {
    PrintHeader("My Wishlist");
    if (user.wishlist.empty()) {
        std::cout << "Your wishlist is empty.\n";
        return;
    }
    for (const Course& c : user.wishlist) {
        std::cout << "[" << c.id << "] " << c.name
                  << " - $" << c.price << "\n";
    }
}

bool IsInWishlist(const User& user, int courseId) {
    for (const Course& c : user.wishlist) {
        if (c.id == courseId) {
            return true;
        }
    }
    return false;
}
