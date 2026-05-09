/* Copyright 2026 Cairo University - SCS253 - Online Learning System
* Implements input validation and console display helper functions.
*/ 

#include "Utils.h"
#include <iostream>
#include <limits>

int GetValidInt(int min, int max) {
    int value = 0;
    while (true) {
        std::cin >> value;
        if (std::cin.fail() || value < min || value > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number between "
                      << min << " and " << max << ": ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

std::string GetValidString(const std::string& prompt) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (!value.empty()) {
            return value;
        }
        std::cout << "Input cannot be empty. Try again.\n";
    }
}

void PrintDivider() {
    std::cout << "----------------------------------------\n";
}

void PrintHeader(const std::string& title) {
    PrintDivider();
    std::cout << "  " << title << "\n";
    PrintDivider();
}
