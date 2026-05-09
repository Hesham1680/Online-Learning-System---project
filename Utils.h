/* Copyright 2026 Cairo University - SCS253 - Online Learning System
* Declares shared utility functions for input validation and display.
*/ 

#ifndef UTILS_H
#define UTILS_H

#include <string>

int GetValidInt(int min, int max);
std::string GetValidString(const std::string& prompt);
void PrintDivider();
void PrintHeader(const std::string& title);

#endif
