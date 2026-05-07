#include "Cart.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

void Cart::addItem(const Course& course) {
    if (contains(course.id)) {
        std::cout << "\"" << course.name << "\" is already in your cart.\n";
        return;
    }
    items.push_back(course);
    std::cout << "\"" << course.name << "\" added to cart.\n";
}

void Cart::removeItem(int courseId) {
    auto it = std::remove_if(items.begin(), items.end(),
        [courseId](const Course& c) { return c.id == courseId; });
    if (it != items.end()) {
        std::cout << "\"" << it->name << "\" removed from cart.\n";
        items.erase(it, items.end());
    } else {
        std::cout << "Course not found in cart.\n";
    }
}

double Cart::getTotal() const {
    double total = 0.0;
    for (const Course& c : items) {
        total += c.price;
    }
    return total;
}

void Cart::display() const {
    printHeader("Your Cart");
    if (items.empty()) {
        std::cout << "Your cart is empty.\n";
        return;
    }
    for (const Course& c : items) {
        std::cout << "- " << c.name
                  << " ($" << std::fixed << std::setprecision(2) << c.price << ")\n";
    }
    printDivider();
    std::cout << "Total: $" << std::fixed << std::setprecision(2) << getTotal() << "\n";
}

bool Cart::isEmpty() const {
    return items.empty();
}

void Cart::clear() {
    items.clear();
}

bool Cart::contains(int courseId) const {
    for (const Course& c : items) {
        if (c.id == courseId) {
            return true;
        }
    }
    return false;
}

void checkout(Cart& cart, User& user) {
    if (cart.isEmpty()) {
        std::cout << "Your cart is empty. Nothing to purchase.\n";
        return;
    }
    cart.display();
    std::cout << "\nConfirm purchase? (1 = Yes, 0 = No): ";
    int confirm = getValidInt(0, 1);
    if (confirm == 0) {
        std::cout << "Purchase cancelled.\n";
        return;
    }
    for (const Course& c : cart.items) {
        bool alreadyOwned = false;
        for (const Course& owned : user.purchasedCourses) {
            if (owned.id == c.id) {
                alreadyOwned = true;
                break;
            }
        }
        if (!alreadyOwned) {
            user.purchasedCourses.push_back(c);
        }
    }
    cart.clear();
    std::cout << "Purchase successful! Courses added to My Courses.\n";
}
