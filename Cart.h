// Defines the Cart struct and declares checkout function.

#ifndef CART_H
#define CART_H

#include <vector>
#include "Course.h"
#include "User.h"

struct Cart {
    std::vector<Course> items;

    void addItem(const Course& course);
    void removeItem(int courseId);
    double getTotal() const;
    void display() const;
    bool isEmpty() const;
    void clear();
    bool contains(int courseId) const;
};

void checkout(Cart& cart, User& user);

#endif
