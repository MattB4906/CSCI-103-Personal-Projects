# Gradebook Manager

A console-based academic gradebook system written in C++. The program allows a user to manage multiple courses, enroll students, record scores, calculate averages, and assign letter grades — all from an interactive menu-driven interface.

## Purpose

This project was built to practice **dynamic memory management**, **multi-file OOP design**, **file I/O**, and **utility function decomposition** in C++. Rather than relying on STL containers, the project intentionally uses **raw dynamic arrays** (`new` / `delete`) to build resizable data structures from scratch, reinforcing low-level memory concepts.

## Features

### Course Management
- Add new courses with a course code and name
- View a list of all courses in the gradebook
- Remove courses by course code
- Courses are stored in a dynamically allocated array that grows as needed

### Student Management
- Enroll students into a specific course by name and ID
- Remove students from a course
- View all students enrolled in a course
- Each course maintains its own dynamically allocated student roster

### Scores & Grades
- Add individual numeric scores to a student's record
- View a student's full score list
- Calculate a student's average score
- Assign a letter grade (A / B / C / D / F) based on the computed average

### File I/O
- Load gradebook data from a `.txt` file at startup
- The file format is CSV-style: `CourseCode, CourseName, StudentID, StudentName, Score1, Score2, ...`
- Supports saving and persisting session data across runs

### Utility Functions
- `calculateWeightedAverage()` — computes a weighted average across scores
- `recursiveSum()` — recursively sums an array of scores
- `assignLetterGrade()` — maps a numeric average to a letter grade

## Class & File Structure

```
Gradebook Manager/
├── main.cpp          # Entry point; menu dispatch and user interaction
├── gradebook.h/.cpp  # Top-level Gradebook: manages a dynamic array of Course*
├── course.h/.cpp     # Course: manages a dynamic array of Student*, file I/O
├── student.h/.cpp    # Student: holds a StudentRecord struct with scores array
└── utils.h/.cpp      # Standalone utility functions (average, grade, recursion)
```

### Object Relationships

```
Gradebook
└── Course[]        (dynamic array of Course pointers)
    └── Student[]   (dynamic array of Student pointers per course)
        └── StudentRecord  (struct: id, name, scores[], numScores)
```

## How to Compile & Run

```bash
g++ -std=c++11 main.cpp student.cpp course.cpp gradebook.cpp utils.cpp -o gradebook
./gradebook
```

## Concepts Demonstrated

- Dynamic memory allocation and deallocation (`new[]` / `delete[]`)
- Pointer-to-pointer arrays (`Course**`, `Student**`) for resizable collections
- Struct-based data records (`StudentRecord`) embedded within classes
- File parsing using `std::ifstream`, `std::stringstream`, and `std::getline`
- Recursive functions for array processing
- Separation of concerns: data model, business logic, and utility functions split across multiple translation units
