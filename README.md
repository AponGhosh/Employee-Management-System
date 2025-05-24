# Employee Management System

A C++-based system to manage employee records using linked lists and file handling, featuring CRUD operations, sorting, and search functionality.


## Overview
The **Employee Management System** is a console-based application designed to store, manage, and organize employee records securely. It uses linked lists for dynamic data storage and file handling for persistence. Key functionalities include adding, deleting, updating, searching, and sorting employee data.

## Features
- **CRUD Operations**:
  - Add new employee records.
  - Delete existing records by ID.
  - Update employee information.
  - Search for employees by ID.
- **Data Display & Sorting**:
  - Display all employee records.
  - Sort records by ID (ascending order) using Bubble Sort.
- **File Handling**:
  - Automatically constructs a linked list from a file database on startup.
  - Saves data in a human-readable file format.

## Functions
| Function            | Description                                                                | Time Complexity  |
|---------------------|----------------------------------------------------------------------------|------------------|
| `addToList()`       | Adds a new employee to the linked list.                                    | **O(n)**         |
| `deleteFromList()`  | Deletes an employee by ID.                                                 | **O(n)**         |
| `update()`          | Updates employee details by ID.                                            | **O(n)**         |
| `searchFromList()`  | Searches for an employee by ID.                                            | **O(n)**         |
| `display()`         | Displays all employee records.                                             | **O(n)**         |
| `sortList()`        | Sorts records by ID (Bubble Sort).                                         | **O(n³)**        |
| `constructList()`   | Converts file data into a linked list on program startup.                  | **O(n)**         |

## Tools
- **Programming Language**: C++
- **Libraries Used**:
  - `<iostream>`: For input/output operations.
  - `<fstream>`: For file handling and data persistence.
  - `<iomanip>`: For formatting output (e.g., aligning table columns).
  - `<cstdlib>`: For system-level operations (e.g., clearing the console).
- **Compiler**: GNU GCC (or any C++11-compatible compiler).
- **Development Environment**: 
  - Code Editors: Visual Studio Code

## Clone the repository
   ```bash
   git clone https://github.com/AponGhosh/Employee-Management-System.git
