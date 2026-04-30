# Personal Budget Tracker

A console-based personal finance management tool written in C++. The program allows a user to create spending categories with budget limits, log transactions, persist all data to disk, and generate a variety of financial reports — all from an interactive menu-driven interface.

## Purpose

This project was built to practice **dynamic memory management with auto-resizing arrays**, **operator overloading**, **file serialization**, and **separation of concerns** across multiple classes. It also introduces **Makefile-based build automation**, making it the most complete project in this repository in terms of real-world software structure.

## Features

### Category Management
- Create spending categories (e.g. "Food", "Transport") each with a custom budget limit
- Remove categories by name (also deallocates all associated transactions)
- View a summary of any category, including total spent, remaining budget, and over-budget status
- Display all transactions within a category
- Sort a category's transactions chronologically by date (bubble sort on a pointer array)

### Transaction Management
- Add a transaction with a description, amount, date (`YYYY-MM-DD`), and target category
- Remove a specific transaction from a category by description
- Transactions are stored in a dynamically allocated array inside each `Category` that **automatically doubles in capacity** when full

### File Persistence
- On exit, the full ledger (all categories and transactions) is **saved to `budget.dat`** in a pipe-delimited text format
- On startup, the program **automatically loads** data from `budget.dat` if it exists, restoring the previous session seamlessly
- The file format uses `CATEGORY` and `TRANSACTION` prefixed lines, parsed via `std::stringstream`

### Reports
A dedicated `Report` class (holding a `const` reference to the `Ledger`) provides five report types:
- **Overall Summary** — total budget limit, total spent, and total remaining across all categories
- **Category Breakdown** — per-category spending and remaining budget displayed side by side
- **Over Budget Warnings** — flags any category where spending has exceeded its limit
- **Top Expenses** — displays the top *n* most expensive transactions across all categories
- **Monthly Report** — filters and displays all transactions matching a given month (`YYYY-MM`)

## Class & File Structure

```
Personal Budget Tracker/
├── main.cpp            # Entry point; menu dispatch and handler functions
├── ledger.h/.cpp       # Ledger: top-level manager of a dynamic Category** array; file I/O
├── category.h/.cpp     # Category: budget limit, dynamic Transaction** array, sorting
├── transaction.h/.cpp  # Transaction: description, amount, date; operator overloading; serialization
├── report.h/.cpp       # Report: read-only analytics over a const Ledger reference
├── utils.h/.cpp        # Utils: static input validation helpers and rounding
└── Makefile            # Build automation
```

### Object Relationships

```
Ledger
└── Category[]        (dynamic array, auto-resizing)
    └── Transaction[] (dynamic array, auto-resizing)

Report ──(const ref)──► Ledger
```

## How to Compile & Run

```bash
# Using Make (recommended)
make
./budget

# Manually
g++ -std=c++11 main.cpp transaction.cpp category.cpp ledger.cpp report.cpp utils.cpp -o budget
./budget
```

A `budget.dat` file will be created automatically in the same directory after the first session.

## Concepts Demonstrated

- Dynamic memory allocation and deallocation with **auto-resizing arrays** (doubling strategy)
- **Operator overloading** (`<` and `==` on `Transaction`) for sorting and comparison
- **File serialization and deserialization** using `std::ofstream`, `std::ifstream`, and `std::stringstream`
- **`const` correctness** — `Report` holds a `const Ledger&` to enforce read-only access
- **Static utility methods** for reusable input validation (`getValidString`, `getValidDouble`, `getValidDate`)
- **Makefile** build automation with separate compilation targets
- Clean memory management: destructors cascade from `Ledger` → `Category` → `Transaction`
