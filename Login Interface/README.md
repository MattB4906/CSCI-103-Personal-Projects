# Login Interface

A console-based, role-driven login and management system written in C++. The program simulates a simple organizational platform where three types of users — **Manager**, **Employee**, and **Consumer** — each log in with their credentials and interact with a personalized menu of actions.

## Purpose

This project was built to practice **object-oriented programming** with a focus on **class inheritance**, **encapsulation**, and **polymorphism**. The core idea is a shared `Person` base class that defines common identity and authentication logic, extended by three specialized derived classes that each add their own data and behavior.

## Features

### Authentication
- All three user types share a unified `login()` / `logout()` flow defined in the `Person` base class
- Credentials (username + password) are validated at login before granting access to any menu
- Each session tracks login state via an `isLoggedIn` flag

### Manager
- Views a roster of all employees under their supervision
- Adds or removes employees by ID
- Assigns and removes named tasks to specific employees
- Views all tasks assigned to a particular employee
- Employees are stored mapped by their ID for efficient lookup

### Employee
- Views their current task list
- Marks tasks as complete by removing them from the list
- Views their own profile information
- Holds a reference to their assigned manager's ID

### Consumer
- Makes purchases by providing an item name and price
- Views their full purchase history
- Checks their total amount spent
- Clears their purchase history
- Account balance is tracked and deducted on each purchase

## Class Hierarchy

```
Person  (base class)
├── Manager   (department, employee roster, task assignment)
├── Employee  (manager reference, task list)
└── Consumer  (account balance, purchase history)
```

## File Structure

```
Login Interface/
├── main.cpp        # Entry point; role selection and menu dispatch
├── person.h/.cpp   # Base class: identity, credentials, login/logout
├── manager.h/.cpp  # Manager: employee and task management
├── employee.h/.cpp # Employee: task list and profile
└── consumer.h/.cpp # Consumer: purchases and account balance
```

## How to Compile & Run

```bash
g++ -std=c++11 main.cpp person.cpp consumer.cpp employee.cpp manager.cpp -o login
./login
```

## Concepts Demonstrated

- Single-inheritance class hierarchy with a virtual base class
- Encapsulation of private member data with public getter/setter methods
- Virtual destructor and virtual `getInfo()` method (polymorphism)
- Use of STL containers: `std::map` (Consumer purchase history, Manager employee roster) and `std::vector` (Employee task list)
- Input validation loops for all menu interactions
