/* Copyright 2026 Cairo University - SCS253 - Online Learning System
* Declares wishlist functions for saving and retrieving courses.
*/

#ifndef WISHLIST_H
#define WISHLIST_H

#include "User.h"
#include "Course.h"

void AddToWishlist(User& user, const Course& course);
void RemoveFromWishlist(User& user, int courseId);
void DisplayWishlist(const User& user);
bool IsInWishlist(const User& user, int courseId);

#endif
