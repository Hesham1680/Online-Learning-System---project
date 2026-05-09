/* 
* Copyright 2026 Cairo University - SCS253 - Online Learning System
* Defines the Cart struct and declares checkout function.
*/
#ifndef CART_H
#define CART_H

#include <vector>
#include "Course.h"
#include "User.h"

struct Cart {
    std::vector<Course> items;

    // Adds a course to the cart. Skips if the course is already present.
    void AddItem(const Course& course);
    //Removes a course from the cart by its ID.
    void RemoveItem(int courseId);
    // Returns the total price of all courses currently in the cart.
    double GetTotal() const;
    // Displays all cart items and the total price.
    void Display() const;
    // Returns true if the cart has no items.
    bool IsEmpty() const;
    // Clears all items from the cart.
    void Clear();
    // Returns true if a course with the given ID is already in the cart.
    bool Contains(int courseId) const;
};

void Checkout(Cart& cart, User& user);

#endif
