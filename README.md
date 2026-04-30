# CSCI-103 Personal Projects

This repository contains personal C++ projects developed alongside USC's **CSCI-103: Introduction to Programming** course. Each project was independently designed and built to reinforce and extend the object-oriented programming concepts covered in class, including class design, inheritance, dynamic memory management, and multi-file compilation.

## Author

**Matteo Benvenuti**  
University of Southern California  
B.S. Computer Science and Business Administration (CSBA)

## Projects

| Project | Description |
|---|---|
| [Login Interface](./Login%20Interface/) | A role-based login system with three user types: Manager, Employee, and Consumer |
| [Gradebook Manager](./Gradebook%20Manager/) | A gradebook system for managing courses, students, and academic scores |
| [Personal Budget Tracker](./Personal%20Budget%20Tracker/) | A personal finance tracker with categorized spending, budget limits, file persistence, and reporting |

## Tech Stack

- **Language:** C++ (C++11 standard)
- **Paradigm:** Object-Oriented Programming (OOP)
- **Compilation:** `g++ -std=c++11` or `make` (where a Makefile is provided)

## How to Compile & Run

Each project lives in its own subdirectory. Navigate into a project folder and compile all `.cpp` files together. For example:

```bash
# Login Interface
cd "Login Interface"
g++ -std=c++11 main.cpp person.cpp consumer.cpp employee.cpp manager.cpp -o login
./login

# Gradebook Manager
cd "Gradebook Manager"
g++ -std=c++11 main.cpp student.cpp course.cpp gradebook.cpp utils.cpp -o gradebook
./gradebook

# Personal Budget Tracker
cd "Personal Budget Tracker"
make
./budget
```

## Course Context

CSCI-103 (Introduction to Programming) at USC covers foundational programming concepts in C++, including variables, control flow, functions, arrays, pointers, and an introduction to classes and object-oriented design. These projects go beyond the standard coursework by implementing multi-class inheritance hierarchies, dynamic memory allocation, file I/O, STL containers, operator overloading, and Makefile-based build automation.
