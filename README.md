# OOP_School_Management_System
This project implements a classroom management system in C++. It allows users to register as students or teachers, view their classes, and perform various actions depending on their roles.

## Classroom Management System - Semester-End Project

This project implements a classroom management system in C++. It allows users to register as students or teachers, view their classes, and perform various actions depending on their roles.

**Features:**

* User login and registration for students and teachers
* Ability for students to view registered classes, attempt assignments, and see notifications
* Ability for teachers to view taught classes, create assignments, add/remove students from classes, and create new classes
* Polymorphism for consistent class viewing functionality across students and teachers

**Files:**

* `Project.h`: Contains class definitions for `Notification`, `User` (base class), `Student`, `Teacher`, `Assignments`, and `Classroom`
* `main.cpp`: Implements the main program logic, including user interaction, menu handling, and function calls to other classes

**Additional Notes:**

* The code utilizes `conio.h` for password masking, which might be specific to certain systems (Windows).
* The `Student::RegisterClass()` and `Classroom::addStudent()` functions are not implemented in the provided code snippet.

This project demonstrates a basic understanding of object-oriented programming concepts like classes, inheritance, polymorphism, and file handling. It can be further extended to include functionalities like attendance management, grade calculation, and communication features.
