// Implements course listing, course detail display, and course creation.

#include "Course.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

std::vector<Course>& getCourseList() {
    static std::vector<Course> courses = {
        {1, "C++ Programming", "Learn C++ from scratch.", "Programming", 49.99, 20, true, "Beginner", "Dr. Ahmed"},
        {2, "Data Structures", "Arrays, linked lists, trees.", "Programming", 59.99, 30, true, "Intermediate", "Dr. Sara"},
        {3, "Web Development", "HTML, CSS, JavaScript.", "Web", 39.99, 25, false, "Beginner", "Dr. Khaled"},
        {4, "Machine Learning", "Intro to ML algorithms.", "AI", 79.99, 40, true, "Advanced", "Dr. Mona"},
        {5, "Database Systems", "SQL and relational models.", "Database", 44.99, 18, true, "Intermediate", "Dr. Omar"},
    };
    return courses;
}

void displayCourseList(bool subscriberMode) {
    std::vector<Course>& courses = getCourseList();
    printHeader("Available Courses");
    std::cout << std::left
              << std::setw(4)  << "ID"
              << std::setw(25) << "Name"
              << std::setw(15) << "Difficulty"
              << std::setw(8)  << "Hours"
              << "Price\n";
    printDivider();
    for (const Course& c : courses) {
        std::cout << std::left
                  << std::setw(4)  << c.id
                  << std::setw(25) << c.name
                  << std::setw(15) << c.difficulty
                  << std::setw(8)  << c.hours;
        if (subscriberMode) {
            std::cout << "FREE\n";
        } else {
            std::cout << "$" << std::fixed << std::setprecision(2) << c.price << "\n";
        }
    }
}

void displayCourseDetail(const Course& course, bool subscriberMode) {
    printHeader(course.name);
    std::cout << "Description : " << course.description << "\n";
    std::cout << "Category    : " << course.category << "\n";
    std::cout << "Instructor  : " << course.instructorName << "\n";
    std::cout << "Difficulty  : " << course.difficulty << "\n";
    std::cout << "Hours       : " << course.hours << "\n";
    std::cout << "Certificate : " << (course.hasCertification ? "Yes" : "No") << "\n";
    if (subscriberMode) {
        std::cout << "Price       : FREE (Subscriber)\n";
    } else {
        std::cout << "Price       : $" << std::fixed << std::setprecision(2) << course.price << "\n";
    }
}

void addCourse(const Course& course) {
    getCourseList().push_back(course);
}
