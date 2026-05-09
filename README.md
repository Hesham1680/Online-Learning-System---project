# Online Learning System
**SCS253 - Software Process and Quality Management - Spring 2026**
Cairo University - Faculty of Computing and Artificial Intelligence

---

## Project Overview

A C++ console application that simulates an online learning platform. Students can browse courses, manage a cart, purchase courses, and save courses to a wishlist. Instructors can add new courses to the platform.

---

## Team Members

| Name | ID |
|---|---|
| Hesham Sherif Ahmed | 20246123 |
| Nour Raef Rabia | 20246118 |
| Yassin Wael Mohamed Abdelaziz | 20246129 |
| Zyad Ashraf Salem | 20246154 |
| Ahmed Yasser Abdelrahman | 20246016 |
| Mazen Mohamed Abdallah | 20246088 |
| Dani George | 20246152 |

---

## Features

**Student**
- Sign up and log in
- Browse all available courses
- View full course details (name, description, hours, certification, difficulty, price)
- Add courses to cart and view cart total
- Purchase courses and access them in My Courses
- Save courses to a wishlist

**Instructor**
- Log in with instructor role
- Add new courses with full details
- View all available courses

---

## Project Structure

```
online-learning-system/
├── .github/
│   └── workflows/
│       └── ci.yml
├── User.h / User.cpp
├── Course.h / Course.cpp
├── Cart.h / Cart.cpp
├── Wishlist.h / Wishlist.cpp
├── Utils.h / Utils.cpp
├── main.cpp
├── LIFECYCLE.md
└── README.md
```

---

## Development Process

This project followed the Scrum framework across 3 one-week sprints.

| Sprint | Goal | Stories |
|---|---|---|
| Sprint 1 | Authentication and course browsing | US-01, US-02, US-03, US-04 |
| Sprint 2 | Cart, purchase, and My Courses | US-05, US-06, US-07 |
| Sprint 3 | Wishlist, instructor features, SonarQube | US-08, US-09 |

---

## CI/CD

GitHub Actions runs on every push to main. The workflow installs g++ on Ubuntu and compiles the full codebase. A passing build confirms zero compilation errors.

---

## Code Quality
 
SonarQube static analysis was run on the full codebase in Sprint 3.
 
- Critical issues: 0
- Blocker issues: 0
- Maintainability rating: A
- Duplications: 0.0%

