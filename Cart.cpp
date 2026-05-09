/* Copyright 2026 Cairo University - SCS253 - Online Learning System
 * Implements cart operations: add, remove, total calculation, and checkout. */

#include "Cart.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

void Cart::AddItem(const Course& course) {
    if (Contains(course.id)) {
        std::cout << "\"" << course.name << "\" is already in your cart.\n";
        return;
    }
    items.push_back(course);
    std::cout << "\"" << course.name << "\" added to cart.\n";
}

void Cart::RemoveItem(int courseId) {
    auto it = std::remove_if(items.begin(), items.end(),
        [courseId](const Course& c) { return c.id == courseId; });
    if (it != items.end()) {
        std::cout << "\"" << it->name << "\" removed from cart.\n";
        items.erase(it, items.end());
    } else {
        std::cout << "Course not found in cart.\n";
    }
}

double Cart::GetTotal() const {
    double total = 0.0;
    for (const Course& c : items) {
        total += c.price;
    }
    return total;
}

void Cart::Display() const {
    PrintHeader("Your Cart");
    if (items.empty()) {
        std::cout << "Your cart is empty.\n";
        return;
    }
    for (const Course& c : items) {
        std::cout << "- " << c.name
                  << " ($" << std::fixed << std::setprecision(2) << c.price << ")\n";
    }
    PrintDivider();
    std::cout << "Total: $" << std::fixed << std::setprecision(2) << GetTotal() << "\n";
}

bool Cart::IsEmpty() const {
    return items.empty();
}

void Cart::Clear() {
    items.clear();
}

bool Cart::Contains(int courseId) const {
    for (const Course& c : items) {
        if (c.id == courseId) {
            return true;
        }
    }
    return false;
}

void Checkout(Cart& cart, User& user) {
    if (cart.IsEmpty()) {
        std::cout << "Your cart is empty. Nothing to purchase.\n";
        return;
    }
    cart.Display();
    std::cout << "\nConfirm purchase? (1 = Yes, 0 = No): ";
    int confirm = GetValidInt(0, 1);
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
    cart.Clear();
    std::cout << "Purchase successful! Courses added to My Courses.\n";
}
