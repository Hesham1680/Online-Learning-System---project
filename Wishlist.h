// Declares wishlist functions for saving and retrieving courses.

#ifndef WISHLIST_H
#define WISHLIST_H

#include "User.h"
#include "Course.h"

void addToWishlist(User& user, const Course& course);
void removeFromWishlist(User& user, int courseId);
void displayWishlist(const User& user);
bool isInWishlist(const User& user, int courseId);

#endif
