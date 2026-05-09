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

    void AddItem(const Course& course);
    void RemoveItem(int courseId);
    double GetTotal() const;
    void Display() const;
    bool IsEmpty() const;
    void Clear();
    bool Contains(int courseId) const;
};

void Checkout(Cart& cart, User& user);

#endif
