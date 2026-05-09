/*  Copyright 2026 Cairo University - SCS253 - Online Learning System
* Defines the Course struct and declares course-related functions.
*/
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

struct Course {
    int id;
    std::string name;
    std::string description;
    std::string category;
    double price;
    int hours;
    bool hasCertification;
    std::string difficulty;
    std::string instructorName;
};

std::vector<Course>& GetCourseList();
void DisplayCourseList(bool subscriberMode);
void DisplayCourseDetail(const Course& course, bool subscriberMode);
void AddCourse(const Course& course);

#endif
