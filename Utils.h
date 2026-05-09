/* 
* Copyright 2026 Cairo University - SCS253 - Online Learning System
* Declares shared utility functions for input validation and display.
*/ 

#ifndef UTILS_H
#define UTILS_H

#include <string>

int getValidInt(int min, int max);
std::string getValidString(const std::string& prompt);
void printDivider();
void printHeader(const std::string& title);

#endif
