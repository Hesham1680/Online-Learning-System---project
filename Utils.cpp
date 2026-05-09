// Implements input validation and console display helper functions.

#include "Utils.h"
#include <iostream>
#include <limits>

int getValidInt(int min, int max) {
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

std::string getValidString(const std::string& prompt) {
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

void printDivider() {
    std::cout << "----------------------------------------\n";
}

void printHeader(const std::string& title) {
    printDivider();
    std::cout << "  " << title << "\n";
    printDivider();
}
